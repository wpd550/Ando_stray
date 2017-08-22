#include<mysql/mysql.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int  main( int argv,char * args[])
{
     MYSQL *mysql=mysql_init(NULL);
     mysql=mysql_real_connect(mysql,"127.0.0.1",args[1],args[2],"test1",3306,NULL,0);
    if(NULL==mysql){
        printf("mysql connect failt");
        return 0;
    }
   int ret= mysql_query(mysql,"set names utf8");
   if(ret){
       printf("query failt");
       return 0;
   }
   int id=5;
   char * name="xiaocang";
   int age=19;
   int fd=2;
   MYSQL_STMT *stmt=mysql_stmt_init(mysql);

   char *sql="insert into person values(?,?,?,?) ";

   mysql_stmt_prepare(stmt,sql,strlen(sql));

    MYSQL_BIND bind[4];

    bind[0].buffer_type=MYSQL_TYPE_LONG;
    bind[0].is_null=(my_bool *)0;
    bind[0].buffer=&id;
    bind[0].buffer_length=sizeof(id);
    bind[0].length=&bind[0].buffer_length;

    bind[1].buffer_type=MYSQL_TYPE_VAR_STRING;
    bind[1].is_null=(my_bool *)0;
    bind[1].buffer=name;
    bind[1].buffer_length=strlen(name);
    bind[1].length=&bind[0].buffer_length;

    bind[2].buffer_type=MYSQL_TYPE_LONG;
    bind[2].is_null=(my_bool *)0;
    bind[2].buffer=&age;
    bind[2].buffer_length=sizeof(fd);
    bind[2].length=&bind[0].buffer_length;

    bind[3].buffer_type=MYSQL_TYPE_LONG;
    bind[3].is_null=(my_bool *)0;
    bind[3].buffer=&fd;
    bind[3].buffer_length=sizeof(fd);
    bind[3].length=&bind[0].buffer_length;

    mysql_stmt_bind_param(stmt,bind);

    mysql_stmt_execute(stmt);

    mysql_stmt_close(stmt);

    mysql_close(mysql);
    return 0;
}
