#include"stdafx.h"
#include<iostream>
#include<list>
#include<map>
using namespace std;
enum class ConfigType :char
{
	Config1,
	Config2

};

class CompleteSimulation
{
public:
	
	 void simulaiton()
	{
		 RunAlgorithm();
	}
	virtual void RunAlgorithm() = 0
	{
		cout << "base class for add path simulation";
	}

};

class Config1CompleteSimulation : public CompleteSimulation
{
public:
	void RunAlgorithm()
	{
		cout << "Config1 algorithm Impl link";
	}
};
class Config2CompleteSimulation : public CompleteSimulation
{
public:
	void RunAlgorithm()
	{
		cout << "Config2 algorithm Impl link";
	}
};

//int main()
//{
//	CompleteSimulation * copletesimulation = new Config1CompleteSimulation(); // at compile time we know what simulation needed to be called;
//	addpath->simulaiton();
//	
//	
//}
