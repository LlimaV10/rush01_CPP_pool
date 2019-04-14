//
// Created by Artem DAYRABEKOV on 2019-04-14.
//

#ifndef RUSH01_DISKSMODULE_HPP
#define RUSH01_DISKSMODULE_HPP


#include <iostream>
#include "AMonitorModule.hpp"

class DisksModule : public AMonitorModule
{
	public:
		DisksModule();

		DisksModule(DisksModule const &other);

		DisksModule &operator=(DisksModule const &other);

		virtual ~DisksModule();
		void getReadInfo();
		void getWrittenInfo();
		void getInfo();
};


#endif //RUSH01_DISKSMODULE_HPP
