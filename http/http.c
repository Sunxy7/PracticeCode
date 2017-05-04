#include"http.h"


int startup(const char * _ip,int _port)
{
	assert(_ip);
	int sock =socket(AF_INET,SOCK_STREAM,0);
	if (sock<0)
	{
		print_log("socket faild!",FATAL);
		exit(1);
	}
	int opt = 1;
	setsockopt(sock,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt));

	struct sockaddr_in server;
	server.sin_family =AF_INET;
	server.sin_port = htons(_port);
	server.sin_addr.s_addr =inet_addr(_ip);
	if(bind(sock,(struct sockaddr *)&server,sizeof(server))<0)
	{
		print_log("bind faild!",FATAL);
		exit(2);
	}
	if (listen(sock,5)<0)
	{
		print_log("listen faild!",FATAL);
		exit(3);
	}
	print_log("socket create success!",NORMAL);
	return sock;
}

void print_log(const char * mesg, int level)
{
	//daemon
	const char *mesg_list[10]=
	{"NORMAL",
	 "WARNING",
	 "FATAL",
	};
	printf("[%s]  [%s]\n",mesg,mesg_list[level]);
}

//static void echo_errno(int sock,int err_code)
//{
//
//
//
//}

static int get_line(int sock,char *buf,int len)
{
	char c ='\0';
	int i=0;
	while(i<len && c != '\n')
	{
		int s = 0;	
		if((s=recv(sock, &c ,1 ,0) )< 0)
		{
			printf("recv is failed\n");
			return -1;
		}           	
		if (s >0 && c =='\r')
		{
			recv(sock ,&c ,1,MSG_PEEK);
			if (c=='\n')
			{
				recv(sock,&c ,1,0);
			}
			else
			{
				c ='\n';
			}
		}
		buf[i++]=c;
	}
	buf[i]='\0';
	return i;
}

static void clear_header(int sock)
{
	char line[SIZE];
	int ret =0;
	do
	{
		ret =get_line(sock,line,SIZE);
	}
	while(ret != 1 && strcmp(line,"\n")!= 0);
}

static int  echo_www(int sock,const char *path,ssize_t size)//处理非cgi
{
	//printf("non cgi -> echo_www\n");
	int fd=open(path,O_RDONLY);
	if (fd < 0)
	{
		print_log("open failed!\n",WARNING);
		//echo_errno();
		close(fd);
		return 1;
	}
	else
	{
		char *msg ="HTTP/1.0 200 ok\r\n";
		send(sock,msg,strlen(msg),0);
		send(sock,"\r\n",strlen("\r\n"),0);
		int ret = sendfile(sock,fd,NULL,size);
		if(ret<0)
		{
			print_log("sendfile failed!",FATAL);
	      //	echo_errno();
			close(fd);
			return 2;
		}
	}
	close(fd);
	return 3;
}        

static int excu_cgi(int sock, const char * method,const char * path,const char *query_string)
{   //处理cgi模式请求
	printf("excu_cgi\n");
	char buf[SIZE];
	int ret = 0;
	int conten_len = -1;
	char method_env[SIZE/8];
	char query_string_env[SIZE/8];
	char conten_len_env[SIZE/8];
	if (strcasecmp(method,"GET")==0)
	{
		clear_header(sock); //get方法则清空消息报头
	}
	else//post
	{
		do
		{
			ret = get_line(sock,buf,sizeof(buf));
		//	printf("%s\n",);
			if ((ret > 0)&& (strncmp(buf,"Content-Length: ",16)==0))
			{
				conten_len = atoi(buf+1);
			}
		}
		while(ret != 1 && strcmp(buf,"\n") != 0);
	}
		int input[2];
		int output[2];
		pipe(input);
    	pipe(output);
   	    pid_t id =fork();
		if(id <0)
		{
			print_log("fork",FATAL);
			//echo_errno();
			return 10; 
		}
		else if(id ==0)
		{
			//child -> exec cgi_bin
			close(input[1]);
			close(output[0]);

			dup2(input[0],0);
			dup2(output[1],1);

		    sprintf(method_env,"METHOD:%s",method);
 	        putenv(method_env);
	        if(strcasecmp(method,"GET")==0)
			{
			     sprintf(query_string_env,"QUERY_STRING:%s",query_string);
                 putenv(query_string_env);
			}
			else
			{
				sprintf(conten_len_env,"CONTEN_LEN:%s",conten_len);
		        putenv(conten_len_env);
			}
		
			execl(path,path,NULL);
			exit(1);
		}
		else
		{
			//father
			close(input[0]);
			close(output[1]);
			char c ='\0';
			if( strcasecmp(method,"POST")==0)
			{
				int i=0;
				for(i=0;i<conten_len;i++)
				{
					recv(sock,&c,1,0);
					write(input[1],&c,1);
				}
			}
			char *msg ="http/1.0 200 ok";
			send(sock,msg,strlen(msg),0);
			while(read(output[0],&c,1)>0)
			{
				send(sock,&c ,1,0);
			}
			waitpid(id,NULL,0);
		}
	return 0;
}

int handler_sock(int sock)//
{
	//printf("handler_sock\n");
	int ret=0;
	char buf[SIZE];
	int i = 0;
	int j = 0;
	int cgi = 0;
	char method[64];
	char url[SIZE];
	char * query_string = NULL;
	char path[SIZE];
	if (get_line(sock,buf,sizeof(buf))<=0)
	{
		print_log("get_line failed!",FATAL);
        //echo_errno();
		close(sock);
		exit(4);
	}
	//j->  GET /XXX/YYY HTTP/1.0
	while(i<sizeof(method) && j<sizeof(buf) && !isspace(buf[j]))//buf[j] is not space
	{
		method[i]=buf[j];
		i++;
		j++;
	}
	method[i]='\0';
	printf("method:%s \n",method);
	if (strcasecmp(method,"POST")==0)//post 一定用cgi 
	{
		cgi = 1;
	}
	if(j< SIZE && isspace(buf[j]))//non space ->return 0
	{
		j++;
	}

	i=0;
	// j->  /XXX/YYY HTTP/1.0
	// get / http/1.0
	while(i<sizeof(method) && j<sizeof(buf) && !isspace(buf[j]))
	{
		url[i]=buf[j];
		i++;
		j++;
	}
	url[i] = '\0';
	printf("url:%s\n",url);
	if (strcasecmp(method,"POST") && strcasecmp(method,"GET"))
	{
	//	echo_errno();
		print_log("method error!",WARNING);
		close(sock);
		return 5;
	}
	if (strcasecmp(method,"GET")== 0)//get
	{
		printf("method -> get\n");
		query_string =url;
		// url   /xx/yy/xx?data1=1&data2 = 2
		while (*query_string !='\0' && *query_string != '?')
		{
			query_string++;
		}
		if(*query_string == '?')//处理数据，使用cgi 
		{
			*query_string ='\0';
			query_string++;
			cgi = 1;
		}
	}

	printf("query_string is%s \n",query_string);
	//  路径变成wwwroot/index.html/
	sprintf(path,"wwwroot%s",url);
	if (path[strlen(path)-1]=='/')//如果是目录文件，将主页显示出来
	{
		strcat(path,"index.html");
	}
	printf("path is:%s\n",path);
	
	struct stat st;
	if (stat(path,&st) < 0)//获取客户端文件资源的相关信息
	{
		print_log("stat faild!",FATAL);
		//echo_errno();
		return 6;
	}
	else   //file exist!
	{
		printf("file exist! \n");
		//if (S_ISDIR(st.st_mode))   //目录文件，则返回它的首页信息
		//{
		//	printf("is dir !\n");
		//	strcat(path,"/index.html");
		//}
		if((st.st_mode & S_IXUSR)||(st.st_mode & S_IXGRP)||(st.st_mode & S_IXOTH))
	{//具有可执行权限
		printf("is exe !\n");
			cgi=1;
		}
		//printf("is not exe!\n");
	}
	if (cgi)
	{ printf("cgi \n");  
		//cgi
		excu_cgi(sock, method, path,query_string);//处理cgi模式请求
	}
	else
	{
		printf("non cgi");
		// non cgi
		clear_header(sock);
		ret=echo_www(sock, path ,sizeof(path));
		//如果是get方法，但没有参数，且请求资源也不是可执行程序,则返回资源
	}
//	printf("hander_sock finish \n");
	return ret;
}


