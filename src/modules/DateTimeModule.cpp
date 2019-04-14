//
// Created by Artem DAYRABEKOV on 2019-04-14.
//

#include "DateTimeModule.hpp"

DateTimeModule::DateTimeModule()
{}

DateTimeModule::DateTimeModule(DateTimeModule const &other) : AMonitorModule(other)
{
	*this = other;
}

DateTimeModule &DateTimeModule::operator=(DateTimeModule const &other)
{
	AMonitorModule::operator=(other);
	return *this;
}

DateTimeModule::~DateTimeModule()
{}

void DateTimeModule::getInfo()
{
	time_t now = time(0);
	struct tm info;
	char temp[80];
	_info.clear();

	info = *localtime(&now);
	strftime(temp, sizeof(temp), "%T %d/%m/%Y", &info);
	std::string str = "Time: ";
	str += temp;
	_info.push_back(str);
}
