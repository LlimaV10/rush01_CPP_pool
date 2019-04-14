/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMonitorModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolilyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 11:54:24 by dbolilyi          #+#    #+#             */
/*   Updated: 2019/04/14 11:54:25 by dbolilyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORMODULE_HPP
# define IMONITORMODULE_HPP

# include <iostream>
#include <vector>
#include "IMonitorModule.hpp"

class AMonitorModule : public IMonitorModule
{
	protected:
		std::vector<std::string>			_info;

		static std::string					_top;
		static std::string			getOutStr(const char* s);
	public:
		AMonitorModule(void);
		AMonitorModule(AMonitorModule const &);
		virtual ~AMonitorModule();
		AMonitorModule & operator=(AMonitorModule const &);

		static void			getPublicInfo(void);
		std::vector<std::string> &	getString(void);

		const std::vector<std::string> &getMyInfo() const;
};




#endif
