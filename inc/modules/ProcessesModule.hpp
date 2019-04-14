//
// Created by Artem DAYRABEKOV on 2019-04-14.
//

#ifndef RUSH01_PROCESSES_HPP
#define RUSH01_PROCESSES_HPP


#include <iostream>
#include "AMonitorModule.hpp"

class ProcessesModule : public AMonitorModule
{
	public:
		ProcessesModule();

		ProcessesModule(ProcessesModule const &other);

		ProcessesModule &operator=(ProcessesModule const &other);

		virtual ~ProcessesModule();

		void getInfo();
};


#endif //RUSH01_PROCESSES_HPP
