//
// Created by Artem DAYRABEKOV on 2019-04-14.
//

#ifndef RUSH01_DATETIMEMODULE_HPP
#define RUSH01_DATETIMEMODULE_HPP


#include <iostream>
#include "AMonitorModule.hpp"

class DateTimeModule : public AMonitorModule
{
	public:
		DateTimeModule();

		DateTimeModule(DateTimeModule const &other);

		DateTimeModule &operator=(DateTimeModule const &other);

		virtual ~DateTimeModule();
		void getInfo();
};


#endif //RUSH01_DATETIMEMODULE_HPP
