#pragma once
#include <string>
using namespace std; 

class Country
{
//�Ӽ� / Attribute / Property
public:
    string Code, Name, Continent, Region, SurfaceArea;
    string IndepYear, Population, LifeExpectancy, GNP, GNPOld;
    string LocalName, GovernmentForm, HeadOfState, Capital, Code2;

//�Լ� / Function / Method
public:  //�ۺ� ������ ����Ʈ�� private
	Country()
	{
        Code = Name = Continent = Region = SurfaceArea = "";
        IndepYear = Population = LifeExpectancy = GNP = GNPOld = "";
        LocalName = GovernmentForm = HeadOfState = Capital = Code2 = "";
	} //������
	~Country(){} //�Ҹ���
	
	void print()
	{   
        // this-> �Ǵ� ��� ����.
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