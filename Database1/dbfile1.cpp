// dbstudy.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
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

    printf("argv[0] = %s\n", argv[0]);  //프로그램
    printf("argv[1] = %s\n", argv[1]);  //user
    printf("argv[2] = %s\n", argv[2]);  //dbname
    printf("argv[3] = %s\n", argv[3]);  //table_name

    // mysql db를 사용하기 위한 변수 선언
    MYSQL mysql;
   

    // 변수 초기화
    if (mysql_init(&mysql) == NULL)
    {
        printf("Fail to initialize mysql\n");
        return 1;
    }


    // 데이터베이스 연결
    if (mysql_real_connect(&mysql, "localhost", argv[1], "tiger", argv[2], 0, 0, 0) == NULL)
    {
        printf("%s\n", mysql_error(&mysql));
        return 1;
    }

    // 질의 전달
    char sql[256];
    sprintf_s(sql, "select * from %s", argv[3]);
    if (mysql_query(&mysql, sql) != 0)
    {
        printf("%s\n", mysql_error(&mysql));
        mysql_close(&mysql);
        return 1;
    }    

    // 질의 결과 저장
    MYSQL_RES* res = mysql_store_result(&mysql); //위에랑 달리 res 라는 변수에 넣었으므로 오류 발생시 밑의 내용과 같이 코드해야 함.
    if (res == NULL) // if(!res) 같은 표현
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

    // 질의 결과 필드 수
    int fieldCount = mysql_num_fields(res);

    // 질의 결과에서 필드(field)별로 하나씩 담을 변수
    MYSQL_FIELD* fields;
    // 필드 값
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

    // 질의 결과에서 레코드(row)별로 하나씩 담을 변수
    MYSQL_ROW row;

    // 모든 레코드를 다 읽을 때까지 반복 수행
    while (row = mysql_fetch_row(res))
    {

        // 읽어들은 한 레코드를 출력
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

    // 질의 결과 메모리 해제
    mysql_free_result(res);

    // 데이터베이스 닫기
    mysql_close(&mysql);
}
