/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NcurDisplay.class.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolilyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 13:04:06 by dbolilyi          #+#    #+#             */
/*   Updated: 2019/04/14 13:04:07 by dbolilyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NcurDisplay.class.hpp"

NcurDisplay::NcurDisplay(void)
{
}

NcurDisplay::NcurDisplay(NcurDisplay const &d)
{
	*this = d;
}

NcurDisplay::~NcurDisplay()
{
}

NcurDisplay & NcurDisplay::operator=(NcurDisplay const &d)
{
	if (this != &d)
	{
		_win = d.getWin();
	}
	return *this;
}

void	NcurDisplay::drawVec(std::vector<std::string> &v, int &x, int &y, int pair)
{
	std::vector<std::string>::iterator	it;
	std::vector<std::string>::iterator	ite = v.end();

	wattron(_win, COLOR_PAIR(pair));
	for (it = v.begin(); it != ite; ++it)
		mvwprintw(_win, y++, x, (*it).c_str());
	wattroff(_win, COLOR_PAIR(pair));
}

void	NcurDisplay::horizontalLine(int & y)
{
	y++;
	for (int i = 1; i < NCUR_W - 1; i++)
		mvwprintw(_win, y, i, "-");
	y += 2;
}

void	NcurDisplay::drawPet(int & y)
{
	static int numb = 0;

	wattron(_win, COLOR_PAIR(2));
	if (numb == 0)
	{
		mvwprintw(_win, y++, 4, "    (\"`-''-/\").___..--''\"`-._");
		mvwprintw(_win, y++, 4, "     `6_ 6  )   `-.  (     ).`-.__.`)");
		mvwprintw(_win, y++, 4, "     (_Y_.)'  ._   )  `._ `. ``-..-'");
		mvwprintw(_win, y++, 4, "   _..`--'_..-_/  /--'_.' ,'");
		mvwprintw(_win, y++, 4, "  (il),-''  (li),'  ((!.-'");
		numb = 1;
	}
	else
	{
		mvwprintw(_win, y++, 7, "     (\"`-/\")_.-'\"``-._");
		mvwprintw(_win, y++, 7, "      . . `; -._    )-;-,_`)");
		mvwprintw(_win, y++, 7, "     (v_,)'  _  )`-.\\  ``-'");
		mvwprintw(_win, y++, 7, "    _.- _..-_/ / ((.'");
		mvwprintw(_win, y++, 7, "  ((,.-'   ((,/");
		numb = 0;
	}
	wattroff(_win, COLOR_PAIR(2));
}

void	NcurDisplay::drawAll(void)
{
	int		x;
	int		y;

	x = 2;
	y = 2;
	wborder(_win, '|', '|', '-', '-', '*', '*', '*', '*');
	std::vector<AMonitorModule *>::iterator	it;
	std::vector<AMonitorModule *>::iterator	ite = _modules.end();
	int		indx = 0;
	for (it = _modules.begin(); it != ite; ++it) {
		drawVec((*it)->getString(), x, y, _colors[indx]);
		horizontalLine(y);
		indx++;
	}
	drawPet(y);
	horizontalLine(y);
}

void	NcurDisplay::update(void)
{
	AMonitorModule::getPublicInfo();
	_cpu.getInfo();
	_date.getInfo();
	_ram.getInfo();
	_net.getInfo();
	_proc.getInfo();
	_disks.getInfo();
	wclear(_win);
	drawAll();
	wrefresh(_win);
}

void	NcurDisplay::changeOrder(int i)
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

void	NcurDisplay::loop(void)
{
	int		quit = 0;
	char	c;

	while (!quit)
	{
		c = getch();
		if (c == 113)
			quit = 1;
		else if (c >= 49 && c <= 57)
			changeOrder(static_cast<int>(c) - 48);
		update();
	}
	delwin(_win);
	endwin();
}

int		NcurDisplay::initAll(void)
{
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	curs_set(0);

	_win = newwin(NCUR_H, NCUR_W, 1, 3);

	box(_win, 0, 0);

	nodelay(stdscr, true);

	start_color();
	init_pair(1, COLOR_BLUE, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_CYAN, COLOR_BLACK);
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(6, COLOR_YELLOW, COLOR_BLACK);
	init_pair(7, COLOR_WHITE, COLOR_BLACK);
	init_pair(8, COLOR_CYAN, COLOR_CYAN);
	init_pair(9, COLOR_RED, COLOR_RED);
	wborder(_win, '|', '|', '-', '-', '*', '*', '*', '*');
	refresh();
	wrefresh(_win);

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

	_colors.push_back(6);
	_colors.push_back(2);
	_colors.push_back(3);
	_colors.push_back(4);
	_colors.push_back(5);
	_colors.push_back(4);
	_colors.push_back(3);
	_colors.push_back(2);
	_colors.push_back(6);

	return 1;
}

WINDOW *NcurDisplay::getWin() const
{
	return _win;
}
