#pragma once
using namespace std;

class CountryLang
{
    //속성 / Attribute / Property
public:
    string CountryCode, Language, IsOfficial, Percentage;


    //함수 / Function / Method
public:  //퍼블릭 없으면 디폴트가 private
    CountryLang()
    {
        CountryCode = Language = IsOfficial = Percentage = "";

    } //생성자
    ~CountryLang() {} //소멸자

    void print()
    {
        // this-> 또는 없어도 같음.
        printf("%s\n", CountryCode.c_str());
        printf("%s\n", Language.c_str());
        printf("%s\n", IsOfficial.c_str());
        printf("%s\n", Percentage.c_str());
    }
};