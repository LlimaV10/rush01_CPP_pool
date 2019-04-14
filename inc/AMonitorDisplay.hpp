/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMonitorDisplay.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolilyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 11:55:14 by dbolilyi          #+#    #+#             */
/*   Updated: 2019/04/14 11:55:15 by dbolilyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORDISPLAY_HPP
# define IMONITORDISPLAY_HPP

# include "HostUserModule.hpp"
# include "CPUModule.hpp"
# include "DateTimeModule.hpp"
# include "OSInfoModule.hpp"
# include "RAMModule.hpp"
# include "NetworkModule.hpp"
# include "ProcessesModule.hpp"
#include "IMonitorDisplay.hpp"
#include "StorageModule.hpp"
#include "DisksModule.hpp"

class AMonitorDisplay : public IMonitorDisplay
{
	protected:
		int				_mode;
		HostUserModule	_hostUser;
		CPUModule		_cpu;
		DateTimeModule	_date;
		OSInfoModule	_os;
		RAMModule		_ram;
		NetworkModule	_net;
		ProcessesModule	_proc;
		StorageModule	_stor;
		DisksModule		_disks;

		std::vector<AMonitorModule *>	_modules;
		int				_select;
	public:
		AMonitorDisplay(void);
		AMonitorDisplay(AMonitorDisplay const &);
		virtual ~AMonitorDisplay();
		AMonitorDisplay & operator=(AMonitorDisplay const &);

		int getMode() const;

		const HostUserModule &getHostUser() const;

		const CPUModule &getCpu() const;

		const DateTimeModule &getDate() const;

		const OSInfoModule &getOs() const;

		const RAMModule &getRam() const;

		const NetworkModule &getNet() const;

		const ProcessesModule &getProc() const;
};



#endif
