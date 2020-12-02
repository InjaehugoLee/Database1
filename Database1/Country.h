#pragma once
#include <string>
using namespace std; 

class Country
{
//속성 / Attribute / Property
public:
    string Code, Name, Continent, Region, SurfaceArea;
    string IndepYear, Population, LifeExpectancy, GNP, GNPOld;
    string LocalName, GovernmentForm, HeadOfState, Capital, Code2;

//함수 / Function / Method
public:  //퍼블릭 없으면 디폴트가 private
	Country()
	{
        Code = Name = Continent = Region = SurfaceArea = "";
        IndepYear = Population = LifeExpectancy = GNP = GNPOld = "";
        LocalName = GovernmentForm = HeadOfState = Capital = Code2 = "";
	} //생성자
	~Country(){} //소멸자
	
	void print()
	{   
        // this-> 또는 없어도 같음.
        printf("%s\n", this->Code.c_str());
        printf("%s\n", this->Name.c_str());
        printf("%s\n", this->Continent.c_str());
        printf("%s\n", Region.c_str());
        printf("%s\n", SurfaceArea.c_str());
        printf("%s\n", IndepYear.c_str());
        printf("%s\n", Population.c_str());
        printf("%s\n", LifeExpectancy.c_str());
        printf("%s\n", GNP.c_str());
        printf("%s\n", GNPOld.c_str());
        printf("%s\n", LocalName.c_str());
        printf("%s\n", GovernmentForm.c_str());
        printf("%s\n", HeadOfState.c_str());
        printf("%s\n", Capital.c_str());
        printf("%s\n", Code2.c_str());
	}
};