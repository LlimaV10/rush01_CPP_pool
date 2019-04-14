//
// Created by Artem DAYRABEKOV on 2019-04-14.
//

#include "OSInfoModule.hpp"
#include <istream>
#include <modules/OSInfoModule.hpp>


OSInfoModule::OSInfoModule()
{
}

OSInfoModule::OSInfoModule(OSInfoModule const &other) : AMonitorModule(other)
{
	*this = other;
}

OSInfoModule &OSInfoModule::operator=(OSInfoModule const &other)
{
	AMonitorModule::operator=(other);
	return *this;
}

OSInfoModule::~OSInfoModule()
{}

void OSInfoModule::getInfo()
{
	_info.clear();

	_info.push_back("Product name: " + getOutStr("sw_vers -productName"));
	_info.push_back("Product version: " + getOutStr("sw_vers -productVersion"));
}
