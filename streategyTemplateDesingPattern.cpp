#include"stdafx.h"
#include<iostream>
#include<list>
#include<memory>
using namespace std;
enum class ConfigType :char
{
	Config1,
	Config2

};
class CompleteSimulationAlogorithmImpl;
class CompleteSimulation
{
public:
	list<CompleteSimulationAlogorithmImpl*> implList;
	void CompleteSimulation::addImpl(ConfigType config);
	
	void CompleteSimulation::RunAlgorithm();

};
class CompleteSimulationAlogorithmImpl
{
public:
	virtual void runImplAlgorithm() = 0;
	static CompleteSimulationAlogorithmImpl * getImpl(ConfigType config);//factory method pattern design pattern

};
class Config1SimulationAlgorithmImpl : public CompleteSimulationAlogorithmImpl
{
public:
	void runImplAlgorithm()
	{
		cout << "Config1 algorithm Impl link";
	}
};
class Config2SimulationAlgorithmImpl : public CompleteSimulationAlogorithmImpl
{
public:
	void runImplAlgorithm()
	{
		cout << "Config2 alorithm Impl Link";
	}
};
CompleteSimulationAlogorithmImpl* CompleteSimulationAlogorithmImpl::getImpl(ConfigType config)
{

	if (config == ConfigType::Config1)
		return new Config1SimulationAlgorithmImpl();
	if (config == ConfigType::Config2)
		return new Config2SimulationAlgorithmImpl();

}
void CompleteSimulation :: addImpl(ConfigType config)
{
	implList.push_back(CompleteSimulationAlogorithmImpl::getImpl(config));
}
void CompleteSimulation :: RunAlgorithm()
{
	for (auto itr : implList)
	{
		itr->runImplAlgorithm();    //streadegy design pattern// we are chaing the algorithm at run time.
	}
}

//int main()
//{
//	CompleteSimulation * completesimulation = new CompleteSimulation();
//	completesimulation->addImpl(ConfigType::Config1);
//	completesimulation->RunAlgorithm();
//	
//	unique_ptr<int> p(new int());
//	
//
//}
