//
// Created by Artem DAYRABEKOV on 2019-04-14.
//

#ifndef RUSH01_OSINFOMODULE_HPP
#define RUSH01_OSINFOMODULE_HPP


#include <iostream>
#include "AMonitorModule.hpp"

class OSInfoModule : public AMonitorModule
{
	private:
		std::string _username;
		std::string _hostname;
		std::string _osName;
		std::string _osVersion;
	public:
		OSInfoModule();

		OSInfoModule(OSInfoModule const &other);

		OSInfoModule &operator=(OSInfoModule const &other);

		virtual ~OSInfoModule();

		void getInfo();
};


#endif //RUSH01_OSINFOMODULE_HPP
