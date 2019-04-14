/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NcurDisplay.class.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolilyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 13:04:16 by dbolilyi          #+#    #+#             */
/*   Updated: 2019/04/14 13:04:17 by dbolilyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NCURDISPLAY_HPP
# define NCURDISPLAY_HPP

# include "AMonitorDisplay.hpp"
# include "gkrellmDef.hpp"

class NcurDisplay : public AMonitorDisplay
{
	private:
		WINDOW	*_win;
		std::vector<int>	_colors;
	public:
		NcurDisplay(void);
		NcurDisplay(NcurDisplay const &);
		virtual ~NcurDisplay();
		NcurDisplay & operator=(NcurDisplay const &);

		void	drawAll(void);
		void	update(void);
		void	loop(void);
		int		initAll(void);
		void	drawVec(std::vector<std::string> &, int &, int &, int);
		void	horizontalLine(int & y);
		void	drawPet(int & y);
		void	changeOrder(int i);
		WINDOW *getWin() const;
};

#endif
