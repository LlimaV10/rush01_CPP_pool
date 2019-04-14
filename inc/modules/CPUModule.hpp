//
// Created by Artem DAYRABEKOV on 2019-04-14.
//

#ifndef RUSH01_CPUMODULE_HPP
#define RUSH01_CPUMODULE_HPP


#include <iostream>
#include "AMonitorModule.hpp"

class CPUModule : public AMonitorModule
{
	public:
		CPUModule();

		CPUModule(CPUModule const &other);

		CPUModule &operator=(CPUModule const &other);

		virtual ~CPUModule();
		void getInfo();
		void getCoreNums();
		void getCoreUsage();
		void getCoreInfo();
};


#endif //RUSH01_CPUMODULE_HPP
