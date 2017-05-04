#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/sendfile.h>
#include<sys/stat.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<fcntl.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<assert.h>


#define SIZE 4096
#define NORMAL 0
#define WARNING 1
#define FATAL 2


int startup(const char * _ip,int port);
int  handler_sock(int sock);
void print_log(const char * mesg, int level);




