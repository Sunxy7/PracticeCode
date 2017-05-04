#include"http.h"

static void  Usage(const char *arg)
{
	printf("Usage:%s [local ip] [local port]\n",arg);
}

static void * accept_request(void *arg)
{
	int sock =(int) arg;
	pthread_detach(pthread_self());
	return (void *) handler_sock(sock);
}
int main(int argc,char * argv[])
{
	int sock;
	if (argc != 3)
	{
		Usage(argv[0]);
		return 1;
	}
	int listen_sock = startup(argv[1],atoi(argv[2]));
	struct sockaddr_in client;
	socklen_t len = sizeof(client);
	while(1)
	{
		if((sock = accept(listen_sock,(struct sockaddr *)(& client),&len))<0)
		{
			print_log("accept faild!",FATAL);
			return 2; 
		}
		pthread_t tid;
		int ret =pthread_create(&tid ,NULL,accept_request,(void *)sock);
		printf("pthread_cteate ret is %d\n",ret);
		if (ret < 0)
		{
			print_log("pthread_create",FATAL);
			close(sock);
			return 3;
		}	
		//pthread_join

	}
	return 0;
}







