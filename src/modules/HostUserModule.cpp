/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HostUserModule.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolilyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 13:51:58 by dbolilyi          #+#    #+#             */
/*   Updated: 2019/04/14 13:51:58 by dbolilyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <modules/HostUserModule.hpp>

#include "HostUserModule.hpp"

HostUserModule::HostUserModule(void)
{
}

HostUserModule::~HostUserModule()
{
}

void	HostUserModule::getInfo(void)
{
	_info.clear();

	std::string		s = "HostName: "+ getOutStr("echo $(logname)");
	_info.push_back(s);
	s = "UserName: " + getOutStr("hostname");
	_info.push_back(s);
}

HostUserModule::HostUserModule(HostUserModule const &other) : AMonitorModule(other)
{
}

HostUserModule &HostUserModule::operator=(HostUserModule const &other)
{
	AMonitorModule::operator=(other);
	return *this;
}

