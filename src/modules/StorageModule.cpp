//
// Created by Artem DAYRABEKOV on 2019-04-14.
//

#include <modules/StorageModule.hpp>

#include "StorageModule.hpp"

StorageModule::StorageModule()
{}

StorageModule::StorageModule(StorageModule const &other) : AMonitorModule(other)
{
	*this = other;
}

StorageModule &StorageModule::operator=(StorageModule const &other)
{
	AMonitorModule::operator=(other);
	return *this;
}

StorageModule::~StorageModule()
{}

void StorageModule::getInfo()
{
	_info.clear();
	_info.push_back("Capacity: ");
	getTotalCapacity();
	getAvailableCapacity();
}

void StorageModule::getTotalCapacity()
{
	std::string erase = "Capacity: ";
	std::string temp = getOutStr("system_profiler SPStorageDataType | grep 'Capacity' | tail -n1");
	temp = temp.erase(temp.find(erase), erase.length());
	temp = temp.substr(0, temp.find(" ("));
	_info.push_back("    Total:     " + temp);
}

void StorageModule::getAvailableCapacity()
{
	std::string erase = "Available: ";
	std::string temp = getOutStr("system_profiler SPStorageDataType | grep 'Available' | tail -n1");
	temp = temp.erase(temp.find(erase), erase.length());
	temp = temp.substr(0, temp.find(" ("));
	_info.push_back("    Available: " + temp);
}

