// dbstudy.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#include <vector>

#include "mysql.h"
#include "Country.h"
#include "City.h"
#include "CountryLang.h"

using namespace std;
#define FIELDS_COUNTRY "Code, Name, Continent,Region, SurfaceArea, IndepYear, Population, LifeExpectancy, GNP, GNPOld, LocalName, GovernmentForm, HeadOfState, Capital, Code2"
#define FIELDS_CITY "ID, Name, CountryCode, District, Population"
#define FIELDS_COUNTRYLANGUAGE "CountryCode, Language, IsOfficial, Percentage"

// 방법 1
void printData(const vector <Country*>& vec)
{
    for (auto pc : vec)
    {
        pc->print();
        printf("===============================\n");
    }
}

// 방법 2
//void printData(const vector <Country*>& vec)
//{
//    for (auto pc : vec)
//    {
//        printf("%s\n", pc->Code.c_str());
//        printf("%s\n", pc->Name.c_str());
//        printf("%s\n", pc->Continent.c_str());
//        printf("%s\n", pc->Region.c_str());
//        printf("%s\n", pc->SurfaceArea.c_str());
//        printf("%s\n", pc->IndepYear.c_str());
//        printf("%s\n", pc->LifeExpectancy.c_str());
//        printf("%s\n", pc->GNP.c_str());
//        printf("%s\n", pc->Population.c_str());
//        printf("%s\n", pc->GNPOld.c_str());
//        printf("%s\n", pc->LocalName.c_str());
//        printf("%s\n", pc->GovernmentForm.c_str());
//        printf("%s\n", pc->HeadOfState.c_str());
//        printf("%s\n", pc->Capital.c_str());
//        printf("%s\n", pc->Code2.c_str());
//        printf("=========================================\n");
//
//     }
//}
void printData(const vector <City*>& vec)
{
    for (auto pc : vec)
    {
        pc->print();
        printf("===============================\n");
    }
}

void printData(const vector <CountryLang*>& vec)
{
    for (auto pc : vec)
    {
        pc->print();
        printf("===============================\n");
    }
}

int main()
{
    // mysql db를 사용하기 위한 변수 선언
    MYSQL mysql;

    // 변수 초기화
    if (mysql_init(&mysql) == NULL)
    {
        printf("Fail to initialize mysql\n");
        return 1;
    }

    // 데이터베이스 연결
    if (mysql_real_connect(&mysql, "localhost", "scott", "tiger", "world", 0, 0, 0) == NULL)
    {
        printf("%s\n", mysql_error(&mysql));
        return 1;
    }

    // 질의 전달
    char sql[256];
    char sql2[256];
    char sql3[256];
    sprintf_s(sql, "select %s from country", FIELDS_COUNTRY);
    sprintf_s(sql2, "select %s from city", FIELDS_CITY);
    sprintf_s(sql3, "select %s from countrylanguage", FIELDS_COUNTRYLANGUAGE);
    // Country 필드 쿼리
    /* 
    if (mysql_query(&mysql, sql) != 0)
    {
        printf("%s\n", mysql_error(&mysql));
        mysql_close(&mysql);
        return 1;
    }*/ 

    // City 필드 쿼리
    /* 
    if (mysql_query(&mysql, sql2) != 0)
    {
        printf("%s\n", mysql_error(&mysql));
        mysql_close(&mysql);
        return 1;
    }*/

    // Countrylanguage 필드 쿼리
    if (mysql_query(&mysql, sql3) != 0)
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

    // 질의 결과 필드 수
    int fieldCount = mysql_num_fields(res);

    vector<Country*> vec;
    vector<City*> vec1;
    vector<CountryLang*> vec2;

    // 질의 결과에서 레코드(row)별로 하나씩 담을 변수
    MYSQL_ROW row;

    // 모든 레코드를 다 읽을 때까지 반복 수행
  /*  while (row = mysql_fetch_row(res))
    {
        Country* pc = new Country;
        int idx = 0;
        if (row[idx]) pc->Code = row[idx]; idx++;
        if (row[idx])pc->Name = row[idx]; idx++;
        if (row[idx])pc->Continent = row[idx]; idx++;
        if (row[idx])pc->Region = row[idx]; idx++;
        if (row[idx])pc->SurfaceArea = row[idx]; idx++;
        if (row[idx])pc->IndepYear = row[idx]; idx++;
        if (row[idx])pc->Population = row[idx]; idx++;
        if (row[idx])pc->LifeExpectancy = row[idx]; idx++;
        if (row[idx])pc->GNP = row[idx]; idx++;
        if (row[idx])pc->GNPOld = row[idx]; idx++;
        if (row[idx])pc->LocalName = row[idx]; idx++;
        if (row[idx])pc->GovernmentForm = row[idx]; idx++;
        if (row[idx])pc->HeadOfState = row[idx]; idx++;
        if (row[idx])pc->Capital = row[idx]; idx++;
        if (row[idx])pc->Code2 = row[idx]; 

        vec.push_back(pc);
    
    }*/

  /*  while (row = mysql_fetch_row(res))
    {
        City* pc1 = new City;
        int idx = 0;
        if (row[idx]) pc1->ID = row[idx]; idx++;
        if (row[idx]) pc1->Name = row[idx]; idx++;
        if (row[idx]) pc1->CountryCode = row[idx]; idx++;
        if (row[idx]) pc1->District = row[idx]; idx++;
        if (row[idx]) pc1->Population = row[idx]; idx++;
   
        vec1.push_back(pc1);

    }*/

    while (row = mysql_fetch_row(res))
    {
        CountryLang* pc2 = new CountryLang;
        int idx = 0;
        if (row[idx]) pc2->CountryCode = row[idx]; idx++;
        if (row[idx]) pc2->Language = row[idx]; idx++;
        if (row[idx]) pc2->IsOfficial = row[idx]; idx++;
        if (row[idx]) pc2->Percentage = row[idx]; idx++;
        

        vec2.push_back(pc2);

    }

    // 질의 결과 메모리 해제
    mysql_free_result(res);
    // 데이터베이스 닫기
    mysql_close(&mysql);

    // 객체를 출력한다
    printData(vec2);
 
    //for (auto pc : vec)
    //{
    //    printf("%s, ", pc->Code.c_str());
    //    printf("%s, ", pc->Name.c_str());
    //    printf("%s, ", pc->Continent.c_str());
    //    printf("%s, ", pc->Region.c_str());
    //    printf("%s, ", pc->SurfaceArea.c_str());
    //    printf("%s, ", pc->IndepYear.c_str());
    //    printf("%s, ", pc->Population.c_str());
    //    printf("%s, ", pc->LifeExpectancy.c_str());
    //    printf("%s, ", pc->GNP.c_str());
    //    printf("%s, ", pc->GNPOld.c_str());
    //    printf("%s, ", pc->LocalName.c_str());
    //    printf("%s, ", pc->GovernmentForm.c_str());
    //    printf("%s, ", pc->HeadOfState.c_str());
    //    printf("%s, ", pc->Capital.c_str());
    //    printf("%s ", pc->Code2.c_str());
    //    printf("\n");

    //}
    // 객체들을 메모리에서 삭제한다
    // 새로운 버전
    for (auto pc : vec)
       delete pc;

    // 기존 버전
    //for (int i = 0; i < vec.size(); i++)
    //    delete vec[i];

    vec.clear();
}
