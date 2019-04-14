//
// Created by Artem DAYRABEKOV on 2019-04-14.
//

#ifndef RUSH01_RAMMODULE_HPP
#define RUSH01_RAMMODULE_HPP


#include <iostream>
#include "AMonitorModule.hpp"

class RAMModule : public AMonitorModule
{
	private:
		void getMemory();

		void getUsed();

		void getUnused();

	public:
		RAMModule();

		RAMModule(RAMModule const &other);

		RAMModule &operator=(RAMModule const &other);

		virtual ~RAMModule();

		void getInfo();

};

#endif //RUSH01_RAMMODULE_HPP
