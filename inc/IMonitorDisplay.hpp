//
// Created by Artem DAYRABEKOV on 2019-04-14.
//

#ifndef RUSH01_IMONITORDISPLAY_HPP
#define RUSH01_IMONITORDISPLAY_HPP

class IMonitorDisplay
{
	public:
		virtual ~IMonitorDisplay(){}
		virtual void	drawAll(void) = 0;
		virtual void	update(void) = 0;
		virtual void	loop(void) = 0;
		virtual int		initAll(void) = 0;
};
#endif //RUSH01_IMONITORDISPLAY_HPP
