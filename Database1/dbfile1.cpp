// dbstudy.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
//
#include <iostream>
#include "mysql.h""
using namespace std;

int main(int argc, char* argv[])
{
    if (argc != 4)
    {
        printf("Usage: Database1 user dbname table_name\n");
        return 1;
    }

    printf("argv[0] = %s\n", argv[0]);  //���α׷�
    printf("argv[1] = %s\n", argv[1]);  //user
    printf("argv[2] = %s\n", argv[2]);  //dbname
    printf("argv[3] = %s\n", argv[3]);  //table_name

    // mysql db�� ����ϱ� ���� ���� ����
    MYSQL mysql;
   

    // ���� �ʱ�ȭ
    if (mysql_init(&mysql) == NULL)
    {
        printf("Fail to initialize mysql\n");
        return 1;
    }


    // �����ͺ��̽� ����
    if (mysql_real_connect(&mysql, "localhost", argv[1], "tiger", argv[2], 0, 0, 0) == NULL)
    {
        printf("%s\n", mysql_error(&mysql));
        return 1;
    }

    // ���� ����
    char sql[256];
    sprintf_s(sql, "select * from %s", argv[3]);
    if (mysql_query(&mysql, sql) != 0)
    {
        printf("%s\n", mysql_error(&mysql));
        mysql_close(&mysql);
        return 1;
    }    

    // ���� ��� ����
    MYSQL_RES* res = mysql_store_result(&mysql); //������ �޸� res ��� ������ �־����Ƿ� ���� �߻��� ���� ����� ���� �ڵ��ؾ� ��.
    if (res == NULL) // if(!res) ���� ǥ��
    {
        printf("%s\n", mysql_error(&mysql));
        mysql_close(&mysql);
        return 1;
    }

    char fname[256];
    sprintf_s(fname, "./%s", argv[2]);
    CreateDirectory(fname, NULL);

    sprintf_s(fname, "./%s/%s.txt", argv[2], argv[3]);
    FILE* fp;
    errno_t err;
    err = fopen_s(&fp, fname, "wt");

    // ���� ��� �ʵ� ��
    int fieldCount = mysql_num_fields(res);

    // ���� ������� �ʵ�(field)���� �ϳ��� ���� ����
    MYSQL_FIELD* fields;
    // �ʵ� ��
    fields = mysql_fetch_fields(res);
    for (int i = 0; i < fieldCount; i++)
    {
        if (i != 0)
        {
            printf(",");
            if (fp) fprintf_s(fp, ",");
        }
        printf("%s", fields[i].name);
        if (fp) fprintf_s(fp, "%s", fields[i].name);
    }
    printf("\n");
    if (fp) fprintf_s(fp, "\n");

    // ���� ������� ���ڵ�(row)���� �ϳ��� ���� ����
    MYSQL_ROW row;

    // ��� ���ڵ带 �� ���� ������ �ݺ� ����
    while (row = mysql_fetch_row(res))
    {

        // �о���� �� ���ڵ带 ���
        for (int i = 0; i < fieldCount; i++)
        {
            if (i == 0)
            {
                printf("%s", row[i]);
                if (fp) fprintf_s(fp, "%s", row[i]);
            }
            else
            {
                printf(",%s", row[i]);
                if (fp) fprintf_s(fp, ",%s", row[i]);
            }
        }
        printf("\n");
        if (fp) fprintf_s(fp, "\n");
    }

    if (fp) fclose(fp);

    // ���� ��� �޸� ����
    mysql_free_result(res);

    // �����ͺ��̽� �ݱ�
    mysql_close(&mysql);
}
