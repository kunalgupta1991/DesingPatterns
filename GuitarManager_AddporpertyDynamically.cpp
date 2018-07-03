#include"stdafx.h"
#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<new>
#include<stdio.h>
#include<assert.h>
#include<memory>
#include<map>
using namespace std;
enum class GuitarProperyType : char
{
	manufracturer,
	strings_count,
	build_year
};
class Guitar
{
private:
	map<GuitarProperyType, string> guitarproperty;
	set<GuitarProperyType> properties;
public:
	Guitar()
	{
		
	}
	string getpropertyval(GuitarProperyType t)
	{
		if (guitarproperty.find(t) != guitarproperty.end())
			return guitarproperty[t];
		else
			return "null";
	}
	bool operator==(Guitar & rhs)
	{
		for (auto &itr : rhs.properties)
		{
			if (guitarproperty[itr] != rhs.getpropertyval(itr))
				return false;
		}
		return true;
	}
public:
	void addProperty(GuitarProperyType t, string val)
	{
		if (properties.find(t) != properties.end())
			properties.insert(t);
		guitarproperty[t] = val;
	}

	
};

//
//int main()
//{
//	Guitar g;
//	g.addProperty(GuitarProperyType::manufracturer, "india");
//	g.addProperty(GuitarProperyType::build_year, "2007");
//	Guitar g2;
//	g2.addProperty(GuitarProperyType::manufracturer, "india");
//	if (g== g2)
//		return true;
//	return 0;
//}
