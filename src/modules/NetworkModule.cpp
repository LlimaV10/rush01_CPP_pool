//
// Created by Artem DAYRABEKOV on 2019-04-14.
//

#include "NetworkModule.hpp"

NetworkModule::NetworkModule()
{}

NetworkModule::NetworkModule(NetworkModule const &other) : AMonitorModule(other)
{
	*this = other;
}

NetworkModule &NetworkModule::operator=(NetworkModule const &other)
{
	AMonitorModule::operator=(other);
	return *this;
}

NetworkModule::~NetworkModule()
{}

void NetworkModule::getInfo()
{
	_info.clear();
	_info.push_back("Network:");
	getInput();
	getOutput();
}

void NetworkModule::getInput()
{
	std::string temp = _top;
	std::string erase = "Networks: packets: ";
	temp = temp.substr(temp.find(erase));
	temp = temp.substr(0, temp.find(" in"));
	temp.erase(temp.find(erase), erase.length());
	_info.push_back("    Input: " + temp);
}

void NetworkModule::getOutput()
{
	std::string temp = _top;
	temp = temp.substr(temp.find("Networks: packets: "));

	std::string erase = ", ";
	temp = temp.substr(temp.find(erase));
	temp = temp.substr(0, temp.find(" out"));
	temp.erase(temp.find(erase), erase.length());
	_info.push_back("    Output: " + temp);
}

