//
// Created by Artem DAYRABEKOV on 2019-04-14.
//

#include "CPUModule.hpp"
#include <sys/sysctl.h>
#include <modules/CPUModule.hpp>


CPUModule::CPUModule()
{}

CPUModule::CPUModule(CPUModule const &other) : AMonitorModule(other)
{
	*this = other;
}

CPUModule &CPUModule::operator=(CPUModule const &other)
{
	AMonitorModule::operator=(other);
	return *this;
}

CPUModule::~CPUModule()
{}

void CPUModule::getInfo()
{
	_info.clear();
	getCoreUsage();
	getCoreNums();
	getCoreInfo();
}
void CPUModule::getCoreNums()
{
	int mib[4];
	int numCPU;
	size_t len = sizeof(numCPU);

/* set the mib for hw.ncpu */
	mib[0] = CTL_HW;
	mib[1] = HW_AVAILCPU;  // alternatively, try HW_NCPU;

/* get the number of CPUs from the system */
	sysctl(mib, 2, &numCPU, &len, NULL, 0);

	_info.push_back("Cores: " + std::to_string(numCPU));
}

void CPUModule::getCoreUsage()
{
	std::string erase = "CPU usage: ";
	std::string temp = _top;
	temp = temp.substr(temp.find(erase));
	temp = temp.substr(0, temp.find("\n"));
	temp.erase(temp.find(erase), erase.length());
	_info.push_back("CPU : " + temp);
}
void CPUModule::getCoreInfo()
{
	std::string temp = getOutStr("sysctl -n machdep.cpu.brand_string");
	_info.push_back("Core info: " + temp);
}

