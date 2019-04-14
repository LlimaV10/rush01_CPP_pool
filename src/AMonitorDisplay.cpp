/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMonitorDisplay.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolilyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 12:30:46 by dbolilyi          #+#    #+#             */
/*   Updated: 2019/04/14 12:30:47 by dbolilyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMonitorDisplay.hpp"

AMonitorDisplay::AMonitorDisplay(void)
	: _hostUser(), _cpu(), _date(), _os(), _ram(), _net(), _proc(), _select(0) {}

AMonitorDisplay::AMonitorDisplay(AMonitorDisplay const &d)
{
	*this = d;
}

AMonitorDisplay::~AMonitorDisplay() {}

AMonitorDisplay & AMonitorDisplay::operator=(AMonitorDisplay const &d)
{
	if (this != &d)
	{
		_mode = d.getMode();
		_hostUser = d.getHostUser();
		_cpu = d.getCpu();
		_date = d.getDate();
		_os = d.getOs();
		_ram = d.getRam();
		_net = d.getNet();
		_proc = d.getProc();
	}
	return *this;
}

int AMonitorDisplay::getMode() const
{
	return _mode;
}

const HostUserModule &AMonitorDisplay::getHostUser() const
{
	return _hostUser;
}

const CPUModule &AMonitorDisplay::getCpu() const
{
	return _cpu;
}

const DateTimeModule &AMonitorDisplay::getDate() const
{
	return _date;
}

const OSInfoModule &AMonitorDisplay::getOs() const
{
	return _os;
}

const RAMModule &AMonitorDisplay::getRam() const
{
	return _ram;
}

const NetworkModule &AMonitorDisplay::getNet() const
{
	return _net;
}

const ProcessesModule &AMonitorDisplay::getProc() const
{
	return _proc;
}
