//
// Created by Artem DAYRABEKOV on 2019-04-14.
//

#ifndef RUSH01_IMONITORMODULE_HPP
#define RUSH01_IMONITORMODULE_HPP
class IMonitorModule
{
	public:
		virtual ~IMonitorModule(){}
		virtual void getInfo(void) = 0;
};

#endif //RUSH01_IMONITORMODULE_HPP
