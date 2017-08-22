#include<mysql/mysql.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argv,char * args[])
{
      MYSQL* mysql=mysql_init(NULL);
      mysql=mysql_real_connect(mysql,"127.0.0.1",args[1],args[2],"test1",3306,NULL,0);
      if(NULL ==mysql){
          printf("database connect failt");
          return -1;
      }
      mysql_query(mysql,"set names utf8");
      char buf[BUFSIZ];
      int ret=0;
      while(1)
      {
        printf("my test->");
        fgets(buf,sizeof(buf),stdin);
        if(strncmp("exit()",buf,6)==0){
            printf("having exit  1 second before!\n");
            sleep(1);
            break;
        }

        ret=mysql_query(mysql,buf);
        if(ret){
            printf("command is wrong please try again ");
            continue;
        }
        //panduan fanhuizi shifo weikong
        MYSQL_RES  *result =mysql_store_result(mysql);
        if(NULL==result)
        {
            unsigned int count=mysql_field_count(mysql);
            if(count){
                printf("select failt and try again");
                continue;
            }
            else
            {

                int n=mysql_affected_rows(mysql);
                 printf("query success affect %d",n);
            }
        }
        else
        {
                unsigned int count=mysql_field_count(mysql);
                MYSQL_FIELD *row= mysql_fetch_fields(result);
                for(int i=0;i<count;i++){
                    printf("%s\t",row[i].name);
                }
                printf("\n");
                MYSQL_ROW data;
                while((data=mysql_fetch_row(result)))
                {
                       for(int i=0;i<count;i++){
                           printf("%s\t",data[i]);
                       }
                       printf("\n");
                }

        }
      }

      mysql_close(mysql);

}
