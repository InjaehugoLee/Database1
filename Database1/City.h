#pragma once
using namespace std;

class City
{
    //속성 / Attribute / Property
public:
    string ID, Name, CountryCode, District, Population;
    

    //함수 / Function / Method
public:  //퍼블릭 없으면 디폴트가 private
    City()
    {
        ID = Name = CountryCode = District = Population = "";
        
    } //생성자
    ~City() {} //소멸자

    void print()
    {
        // this-> 또는 없어도 같음.
        printf("%s\n", ID.c_str());
        printf("%s\n", Name.c_str());
        printf("%s\n", CountryCode.c_str());
        printf("%s\n", District.c_str());
        printf("%s\n", Population.c_str());
       
    }
};