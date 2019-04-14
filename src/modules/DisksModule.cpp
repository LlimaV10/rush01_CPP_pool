//
// Created by Artem DAYRABEKOV on 2019-04-14.
//

#include <modules/DisksModule.hpp>

#include "DisksModule.hpp"

DisksModule::DisksModule()
{}

DisksModule::DisksModule(DisksModule const &other) : AMonitorModule(other)
{
	*this = other;
}

//TODO: add correct variable assignments
DisksModule &DisksModule::operator=(DisksModule const &other)
{
	AMonitorModule::operator=(other);
	return *this;
}

DisksModule::~DisksModule()
{}

void DisksModule::getInfo()
{
	_info.clear();
	_info.push_back("Disks:");
	getReadInfo();
	getWrittenInfo();
}

void DisksModule::getReadInfo()
{
	std::string temp = _top;
	std::string erase = "Disks: ";
	temp = temp.substr(temp.find(erase));
	temp = temp.substr(0, temp.find(" read"));
	temp.erase(temp.find(erase), erase.length());
	_info.push_back("    Read: " + temp);
}

void DisksModule::getWrittenInfo()
{
	std::string temp = _top;
	temp = temp.substr(temp.find("Disks: "));

	std::string erase = ", ";
	temp = temp.substr(temp.find(erase));
	temp = temp.substr(0, temp.find(" written"));
	temp.erase(temp.find(erase), erase.length());
	_info.push_back("    Written: " + temp);
}
