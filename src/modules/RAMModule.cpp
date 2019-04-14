//
// Created by Artem DAYRABEKOV on 2019-04-14.
//

#include <modules/RAMModule.hpp>

#include "RAMModule.hpp"

RAMModule::RAMModule()
{}

RAMModule::RAMModule(RAMModule const &other) : AMonitorModule(other)
{
	*this = other;
}

RAMModule &RAMModule::operator=(RAMModule const &other)
{
	AMonitorModule::operator=(other);
	return *this;
}

RAMModule::~RAMModule()
{}

void RAMModule::getInfo()
{
	_info.clear();
	getMemory();
	getUsed();
	getUnused();
}

void RAMModule::getMemory()
{
	std::string temp = getOutStr("system_profiler SPHardwareDataType");
	std::string erase = "Memory:";

	temp = temp.substr(temp.find("Memory:"));
	temp = temp.substr(0, temp.find("\n"));
	temp.erase(temp.find(erase), erase.length());

	_info.push_back("RAM: " + temp);
}

void RAMModule::getUsed()
{
	std::string temp = _top;
	std::string erase = "PhysMem:";
	temp =  temp.substr(temp.find(erase));
	temp = temp.substr(0, temp.find(" used"));
	temp.erase(temp.find(erase), erase.length());

	_info.push_back("Used: " + temp);
}

void RAMModule::getUnused()
{

	std::string temp = _top;
	std::string erase = "PhysMem:";
	temp = temp.substr(temp.find(erase));
	temp.erase(temp.find(erase), erase.length());

	erase = "wired), ";
	temp = temp.substr(temp.find(erase));
	temp = temp.substr(0, temp.find(" unused"));
	temp.erase(temp.find(erase), erase.length());

	_info.push_back("Unused: " + temp);
}
