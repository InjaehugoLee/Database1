// dbstudy.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
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

// ��� 1
void printData(const vector <Country*>& vec)
{
    for (auto pc : vec)
    {
        pc->print();
        printf("===============================\n");
    }
}

// ��� 2
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
    // mysql db�� ����ϱ� ���� ���� ����
    MYSQL mysql;

    // ���� �ʱ�ȭ
    if (mysql_init(&mysql) == NULL)
    {
        printf("Fail to initialize mysql\n");
        return 1;
    }

    // �����ͺ��̽� ����
    if (mysql_real_connect(&mysql, "localhost", "scott", "tiger", "world", 0, 0, 0) == NULL)
    {
        printf("%s\n", mysql_error(&mysql));
        return 1;
    }

    // ���� ����
    char sql[256];
    char sql2[256];
    char sql3[256];
    sprintf_s(sql, "select %s from country", FIELDS_COUNTRY);
    sprintf_s(sql2, "select %s from city", FIELDS_CITY);
    sprintf_s(sql3, "select %s from countrylanguage", FIELDS_COUNTRYLANGUAGE);
    // Country �ʵ� ����
    /* 
    if (mysql_query(&mysql, sql) != 0)
    {
        printf("%s\n", mysql_error(&mysql));
        mysql_close(&mysql);
        return 1;
    }*/ 

    // City �ʵ� ����
    /* 
    if (mysql_query(&mysql, sql2) != 0)
    {
        printf("%s\n", mysql_error(&mysql));
        mysql_close(&mysql);
        return 1;
    }*/

    // Countrylanguage �ʵ� ����
    if (mysql_query(&mysql, sql3) != 0)
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

    // ���� ��� �ʵ� ��
    int fieldCount = mysql_num_fields(res);

    vector<Country*> vec;
    vector<City*> vec1;
    vector<CountryLang*> vec2;

    // ���� ������� ���ڵ�(row)���� �ϳ��� ���� ����
    MYSQL_ROW row;

    // ��� ���ڵ带 �� ���� ������ �ݺ� ����
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

    // ���� ��� �޸� ����
    mysql_free_result(res);
    // �����ͺ��̽� �ݱ�
    mysql_close(&mysql);

    // ��ü�� ����Ѵ�
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
    // ��ü���� �޸𸮿��� �����Ѵ�
    // ���ο� ����
    for (auto pc : vec)
       delete pc;

    // ���� ����
    //for (int i = 0; i < vec.size(); i++)
    //    delete vec[i];

    vec.clear();
}
