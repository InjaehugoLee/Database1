#pragma once
using namespace std;

class CountryLang
{
    //�Ӽ� / Attribute / Property
public:
    string CountryCode, Language, IsOfficial, Percentage;


    //�Լ� / Function / Method
public:  //�ۺ� ������ ����Ʈ�� private
    CountryLang()
    {
        CountryCode = Language = IsOfficial = Percentage = "";

    } //������
    ~CountryLang() {} //�Ҹ���

    void print()
    {
        // this-> �Ǵ� ��� ����.
        printf("%s\n", CountryCode.c_str());
        printf("%s\n", Language.c_str());
        printf("%s\n", IsOfficial.c_str());
        printf("%s\n", Percentage.c_str());
    }
};