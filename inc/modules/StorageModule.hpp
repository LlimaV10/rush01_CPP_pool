//
// Created by Artem DAYRABEKOV on 2019-04-14.
//

#ifndef RUSH01_STORAGEMODULE_HPP
#define RUSH01_STORAGEMODULE_HPP


#include <iostream>
#include "AMonitorModule.hpp"

class StorageModule : public AMonitorModule
{
	public:
		StorageModule();

		StorageModule(StorageModule const &other);

		StorageModule &operator=(StorageModule const &other);

		virtual ~StorageModule();
		void getTotalCapacity();
		void getInfo();
		void getAvailableCapacity();
};


#endif //RUSH01_STORAGEMODULE_HPP
