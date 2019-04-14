/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMonitorModule.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolilyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 12:30:48 by dbolilyi          #+#    #+#             */
/*   Updated: 2019/04/14 12:30:50 by dbolilyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMonitorModule.hpp"

std::string AMonitorModule::_top = "";


AMonitorModule::AMonitorModule(void)
{
}

AMonitorModule::AMonitorModule(AMonitorModule const &d)
{
	*this = d;
}

AMonitorModule::~AMonitorModule()
{
}

AMonitorModule & AMonitorModule::operator=(AMonitorModule const &d)
{
	if (this != &d)
	{
		_info = d.getMyInfo();
	}
	return *this;
}

std::string		AMonitorModule::getOutStr(const char* s)
{
	FILE*		pipe;
	std::string out = "";
	char		ch[256];
	
	pipe = popen(s, "r");
	if (!pipe)
		return out;
	try
	{
		while (!feof(pipe))
			if (fgets(ch, 256, pipe) != NULL)
				out += ch;
	}
	catch (std::exception &e)
	{
		pclose(pipe);
	}
	pclose(pipe);
	if (out[out.length() - 1] == '\n')
		out = out.substr(0, out.length() - 1);
	return out;
}

void		AMonitorModule::getPublicInfo(void)
{
	_top = getOutStr("top -l1 -n1");
}

std::vector<std::string> &	AMonitorModule::getString(void)
{
	return _info;
}

const std::vector<std::string> &AMonitorModule::getMyInfo() const
{
	return _info;
}
