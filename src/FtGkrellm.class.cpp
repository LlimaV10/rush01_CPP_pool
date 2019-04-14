/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FtGkrellm.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolilyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 12:41:02 by dbolilyi          #+#    #+#             */
/*   Updated: 2019/04/14 12:41:04 by dbolilyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FtGkrellm.class.hpp"

FtGkrellm::FtGkrellm(void)
{
}

FtGkrellm::FtGkrellm(FtGkrellm const &d)
{
	*this = d;
}

FtGkrellm::~FtGkrellm()
{
}

FtGkrellm & FtGkrellm::operator=(FtGkrellm const &other)
{
	if (this != &other)
	{
		_graph = other.getGraph();
		_ncur = other.getNcur();
	}
	return *this;
}

void	FtGkrellm::runSDL(void)
{
	_graph = new GraficDisplay;
	if (!_graph->initAll())
		std::cout << "Initialization error" << std::endl;
	else
		_graph->loop();
}

void	FtGkrellm::runNcur(void)
{
	_ncur = new NcurDisplay;
	if (!_ncur->initAll())
		std::cout << "Initialization error" << std::endl;
	else
		_ncur->loop();
}

GraficDisplay *FtGkrellm::getGraph() const
{
	return _graph;
}

NcurDisplay *FtGkrellm::getNcur() const
{
	return _ncur;
}
