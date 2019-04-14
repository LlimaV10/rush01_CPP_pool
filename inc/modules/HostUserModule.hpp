/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HostUserModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolilyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 13:52:19 by dbolilyi          #+#    #+#             */
/*   Updated: 2019/04/14 13:52:20 by dbolilyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOSTUSERMODULE_HPP
# define HOSTUSERMODULE_HPP

# include "AMonitorModule.hpp"

class HostUserModule : public AMonitorModule
{
	public:
		void	getInfo(void);
		HostUserModule(void);
		HostUserModule(HostUserModule const &other);
		HostUserModule&operator=(HostUserModule const& other);
		virtual ~HostUserModule();


};



#endif
