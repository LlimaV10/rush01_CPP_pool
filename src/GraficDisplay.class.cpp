/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GraficDisplay.class.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolilyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 13:04:05 by dbolilyi          #+#    #+#             */
/*   Updated: 2019/04/14 13:04:06 by dbolilyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <GraficDisplay.class.hpp>

#include "GraficDisplay.class.hpp"

GraficDisplay::GraficDisplay(void)
{
}

GraficDisplay::~GraficDisplay()
{
}

void	GraficDisplay::drawVec(std::vector<std::string> &v, SDL_Rect &r, SDL_Color & col)
{
	std::vector<std::string>::iterator	it;
	std::vector<std::string>::iterator	ite = v.end();
	SDL_Surface	*tmp;

	for (it = v.begin(); it != ite; ++it)
	{
		tmp = TTF_RenderText_Solid(_arial, (*it).c_str(), col);
		SDL_BlitSurface(tmp, 0, _sur, &r);
		SDL_FreeSurface(tmp);
		r.y += 24;
	}
}

void	GraficDisplay::drawHorizontalLine(int &y)
{
	SDL_Rect	r;
	y += 24;
	r.y = y;
	r.x = 0;
	r.w = WINDOW_W;
	r.h = 10;
	SDL_FillRect(_sur, &r, 0xFFFFFF);
	y += 34;
}

void	GraficDisplay::drawVertLines(void)
{
	SDL_Rect	r;

	r.x = 0;
	r.y = 0;
	r.w = 10;
	r.h = WINDOW_H;
	SDL_FillRect(_sur, &r, 0xFFFFFF);
	r.x = WINDOW_W - 10;
	SDL_FillRect(_sur, &r, 0xFFFFFF);
}

void	GraficDisplay::drawPet(SDL_Rect &r)
{
	static int numb = 0;

	SDL_BlitSurface(_img[numb], 0, _sur, &r);
	numb = (numb == 0) ? 1 : 0;
	r.y += 160;
}

void	GraficDisplay::drawAll(void)
{
	
	SDL_Rect	r = {34, -24, 20, 20};

	drawVertLines();
	drawHorizontalLine(r.y);
	std::vector<AMonitorModule *>::iterator	it;
	std::vector<AMonitorModule *>::iterator	ite = _modules.end();
	int		indx = 0;
	for (it = _modules.begin(); it != ite; ++it) {
		drawVec((*it)->getString(), r, *(_colors[indx]));
		drawHorizontalLine(r.y);
		indx++;
	}
	drawPet(r);
	drawHorizontalLine(r.y);
}

void	GraficDisplay::update(void)
{
	AMonitorModule::getPublicInfo();
	_cpu.getInfo();
	_date.getInfo();
	_ram.getInfo();
	_net.getInfo();
	_proc.getInfo();
	_disks.getInfo();
	SDL_FillRect(_sur, &_winRect, 0);
	drawAll();
	SDL_UpdateWindowSurface(_win);
}

void	GraficDisplay::changeOrder(int i)
{
	if (_select == 0)
		_select = i;
	else
	{
		AMonitorModule	*tmp;
		tmp = _modules[i - 1];
		_modules[i - 1] = _modules[_select - 1];
		_modules[_select - 1] = tmp;
		_select = 0;
	}
}

void	GraficDisplay::loop(void)
{
	SDL_Event	e;
	int			quit;

	quit = 0;
	while (!quit)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
				quit = 1;
			else if (e.type == SDL_KEYDOWN && e.key.keysym.scancode == 20)
				quit = 1;
			else if (e.type == SDL_KEYDOWN
				&& e.key.keysym.scancode >= 30 && e.key.keysym.scancode <= 38)
				changeOrder(e.key.keysym.scancode - 29);
		}
		update();
	}

	SDL_DestroyWindow(_win);
	TTF_Quit();
	SDL_Quit();
}

int		GraficDisplay::initAll(void)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	_arial = TTF_OpenFont("frameworks/ARIAL.TTF", 24);
	_img[0] = SDL_LoadBMP("img/0.bmp");
	_img[1] = SDL_LoadBMP("img/1.bmp");
	_win = SDL_CreateWindow("ft_gkrellm",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		WINDOW_W, WINDOW_H, SDL_WINDOW_SHOWN);
	_sur = SDL_GetWindowSurface(_win);
	_winRect.x = 0;
	_winRect.y = 0;
	_winRect.w = WINDOW_W;
	_winRect.h = WINDOW_H;
	if (!_arial || !_win || !_sur || !_img[0] || !_img[1])
		return 0;

	_hostUser.getInfo();
	_os.getInfo();
	_stor.getInfo();

	_modules.push_back(static_cast<AMonitorModule *>(&_hostUser));
	_modules.push_back(static_cast<AMonitorModule *>(&_cpu));
	_modules.push_back(static_cast<AMonitorModule *>(&_date));
	_modules.push_back(static_cast<AMonitorModule *>(&_os));
	_modules.push_back(static_cast<AMonitorModule *>(&_ram));
	_modules.push_back(static_cast<AMonitorModule *>(&_net));
	_modules.push_back(static_cast<AMonitorModule *>(&_proc));
	_modules.push_back(static_cast<AMonitorModule *>(&_stor));
	_modules.push_back(static_cast<AMonitorModule *>(&_disks));

	SDL_Color	col;
	col.r = 255;
	col.g = 255;
	col.b = 0;
	col.a = 255;

	_colors.push_back(new SDL_Color(col));
	col.g = 0;
	_colors.push_back(new SDL_Color(col));
	col.g = 255;
	col.r = 0;
	_colors.push_back(new SDL_Color(col));
	col.b = 255;
	_colors.push_back(new SDL_Color(col));
	col.g = 0;
	col.r = 255;
	_colors.push_back(new SDL_Color(col));
	col.g = 255;
	col.r = 0;
	_colors.push_back(new SDL_Color(col));
	col.b = 0;
	_colors.push_back(new SDL_Color(col));
	col.r = 255;
	_colors.push_back(new SDL_Color(col));
	col.g = 0;
	col.b = 0;
	_colors.push_back(new SDL_Color(col));

	return 1;
}

GraficDisplay::GraficDisplay(GraficDisplay const &other)
{
	*this = other;
}

GraficDisplay &GraficDisplay::operator=(GraficDisplay const &other)
{
	_win = other.getWin();
	_sur = other.getSur();
	_arial = other.getArial();
	_winRect = other.getWinRect();
	return *this;
}

SDL_Window *GraficDisplay::getWin() const
{
	return _win;
}

SDL_Surface *GraficDisplay::getSur() const
{
	return _sur;
}

TTF_Font *GraficDisplay::getArial() const
{
	return _arial;
}

const SDL_Rect &GraficDisplay::getWinRect() const
{
	return _winRect;
}
