#pragma once
using namespace std;

class City
{
    //�Ӽ� / Attribute / Property
public:
    string ID, Name, CountryCode, District, Population;
    

    //�Լ� / Function / Method
public:  //�ۺ� ������ ����Ʈ�� private
    City()
    {
        ID = Name = CountryCode = District = Population = "";
        
    } //������
    ~City() {} //�Ҹ���

    void print()
    {
        // this-> �Ǵ� ��� ����.
        printf("%s\n", ID.c_str());
        printf("%s\n", Name.c_str());
        printf("%s\n", CountryCode.c_str());
        printf("%s\n", District.c_str());
        printf("%s\n", Population.c_str());
       
    }
};