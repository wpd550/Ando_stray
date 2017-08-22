#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mysql/mysql.h"

int main()
{
    MYSQL *mysql=mysql_init(NULL);
    mysql=mysql_real_connect(mysql,"127.0.0.1","root","123456","test1",3306,NULL,0);
    if(NULL == mysql)
    {
        printf("connect errno");
        return -1;
    }
    int re=mysql_query(mysql,"set names utf8");
    if(re){
           printf("set failt");
           return -1;
    }

    re=mysql_query(mysql,"insert into person values(4,'xiaoming',19,1)");
    if(re)
    {
        printf("ddddd");
    }
    re=mysql_affected_rows(mysql);
    printf("affectd %d\n",re);
    mysql_close(mysql);



    return 0;
}
