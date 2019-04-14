//
// Created by Artem DAYRABEKOV on 2019-04-14.
//

#include "ProcessesModule.hpp"

ProcessesModule::ProcessesModule()
{}

ProcessesModule::ProcessesModule(ProcessesModule const &other) : AMonitorModule(other)
{
	*this = other;
}

ProcessesModule &ProcessesModule::operator=(ProcessesModule const &other)
{
	AMonitorModule::operator=(other);
	return *this;
}

ProcessesModule::~ProcessesModule()
{}

void ProcessesModule::getInfo()
{
	_info.clear();
	std::string temp = _top;
	std::string erase = "Pro:";
	temp =  temp.substr(temp.find("Processes"));
	temp = temp.substr(0, temp.find("\n"));
	_info.push_back(temp);
}
