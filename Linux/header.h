#ifndef __HEADER_H
#define __HEADER_H
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdarg.h>
#include<string.h>
#include<sys/socket.h>
#include<netdb.h>
#include<stdlib.h>
#include<ctype.h>
#include<errno.h>
#include<malloc.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/ioctl.h>
#include<fcntl.h>
#include<shadow.h>
#include<crypt.h>
#include<pwd.h>
#include<sys/time.h>
#include<utime.h>
#include<time.h>
#include<sys/stat.h>
#include<sys/file.h>
#include<sys/wait.h>
#include<sys/ipc.h>
#include<pthread.h>
#include<dirent.h>


#define PRINT_ERR 4
#define PRINT_WARN 3
#define PRINT_INFO 2
#define PRINT_DEBUG 1
static int log_level =0;

#define print_info(fmt,...) print_log(PRINT_INFO,__FILE__,__LINE__,fmt,##__VA_ARGS__)
#define print_warn(fmt,...) print_log(PRINT_WARN,__FILE__,__LINE__,fmt,##__VA_ARGS__)
#define print_debug(fmt,...) print_log(PRINT_DEBUG,__FILE__,__LINE__,fmt,##__VA_ARGS__)
#define print_err(fmt,...) print_log(PRINT_ERR,__FILE__,__LINE__,fmt,##__VA_ARGS__)



void print_log(int level,const char *file ,const line,const char *fmt,...)
{
	if(level<log_level)
		return ;
	char buf[4096];
	va_list ap;
	va_start(ap,fmt);
	vsprintf(buf,fmt,ap);
	va_end(ap);
	static const char *l[]=
	{"debug","info","warn","err"};
	printf("[%s] [%s,%d]:%s",l[level-1],file,line,buf);
}

void set_debug_level(int level){
	log_level =level;
}


#endif  //__HEADER_H
