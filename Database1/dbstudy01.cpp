// dbstudy.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
//
#include <iostream>
#include "mysql.h""
using namespace std;


int main(int argc, char* argv[])
{
    if (argc != 4)
    {
        printf("Usage: Database1 dbname user sql-statement\n");
        return 1;
    }
     
    printf("argv[0] = %s\n", argv[0]);  //���α׷�
    printf("argv[1] = %s\n", argv[1]);  //dbname
    printf("argv[2] = %s\n", argv[2]);  //user
    printf("argv[3] = %s\n", argv[3]);  //sql statement

    // mysql db�� ����ϱ� ���� ���� ����
    MYSQL mysql;
    MYSQL_FIELD *fields;

    // ���� �ʱ�ȭ
    if (mysql_init(&mysql) == NULL)
    {
        printf("Fail to initialize mysql\n");
        return 1;
    }
     

    // �����ͺ��̽� ����
   if( mysql_real_connect(&mysql, "localhost", argv[2], "tiger", argv[1], 0, 0, 0)==NULL)
   {
       printf("%s\n", mysql_error(&mysql));
       return 1;
   }

    // ���� ����
   //if (mysql_query(&mysql, "select * from countrylanguage") != 0)
   if (mysql_query(&mysql, argv[3])!= 0)
   {    
      
       printf("%s\n", mysql_error(&mysql));
       mysql_close(&mysql);
       return 1;
   }
   
    // ���� ��� ����
   MYSQL_RES * res = mysql_store_result(&mysql);
   if(!res)
   {
       printf("%s\n", mysql_error(&mysql));
       mysql_close(&mysql);
       return 1;
   }

    // ���� ��� �ʵ� ��
    int fieldCount = mysql_num_fields(res);

    // �ʵ� ��
    fields= mysql_fetch_fields(res);
    for (int i = 0; i < fieldCount; i++)
    {
        printf("%s ", fields[i].name);
    }
    printf("\n");

    // ���� ������� ���ڵ�(row)���� �ϳ��� ���� ����
    MYSQL_ROW row;

    // ��� ���ڵ带 �� ���� ������ �ݺ� ����
    while (row = mysql_fetch_row(res))
    {
        
        // �о���� �� ���ڵ带 ���
        for (int i = 0; i < fieldCount; i++)
        {   
            
            if (i == 0) printf("%s", row[i]);
            else        printf(",%s", row[i]);
        }
        printf("\n");
    }

    // ���� ��� �޸� ����
    mysql_free_result(res);

    // �����ͺ��̽� �ݱ�
    mysql_close(&mysql);
}
