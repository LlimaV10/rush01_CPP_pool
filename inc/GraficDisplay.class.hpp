/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GraficDisplay.class.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolilyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 13:04:15 by dbolilyi          #+#    #+#             */
/*   Updated: 2019/04/14 13:04:16 by dbolilyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAFICDISPLAY_HPP
# define GRAFICDISPLAY_HPP

# include "AMonitorDisplay.hpp"
# include "gkrellmDef.hpp"

class GraficDisplay : public AMonitorDisplay
{
	private:
		SDL_Window	*_win;
		SDL_Surface	*_sur;
		TTF_Font	*_arial;
		SDL_Rect	_winRect;
		SDL_Surface	*_img[2];
		std::vector<SDL_Color *>	_colors;
	public:
		GraficDisplay(void);
		GraficDisplay(GraficDisplay const &other);
		GraficDisplay& operator=(GraficDisplay const &other);
		virtual ~GraficDisplay();

		void	drawAll(void);
		void	update(void);
		void	loop(void);
		int		initAll(void);
		void	drawVec(std::vector<std::string> &, SDL_Rect &, SDL_Color &);
		void	drawHorizontalLine(int &);
		void	drawVertLines(void);
		void	drawPet(SDL_Rect &);
		void	changeOrder(int i);

		SDL_Window *getWin() const;

		SDL_Surface *getSur() const;

		TTF_Font *getArial() const;

		const SDL_Rect &getWinRect() const;
};




#endif
