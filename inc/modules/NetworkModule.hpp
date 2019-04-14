//
// Created by Artem DAYRABEKOV on 2019-04-14.
//

#ifndef RUSH01_NETWORKMODULE_HPP
#define RUSH01_NETWORKMODULE_HPP


#include <iostream>
#include "AMonitorModule.hpp"

class NetworkModule : public AMonitorModule
{
	public:
		NetworkModule();

		NetworkModule(NetworkModule const &other);

		NetworkModule &operator=(NetworkModule const &other);

		virtual ~NetworkModule();
		void getInfo();
		void getInput();
		void getOutput();
};


#endif //RUSH01_NETWORKMODULE_HPP
