/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FtGkrellm.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolilyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 12:41:10 by dbolilyi          #+#    #+#             */
/*   Updated: 2019/04/14 12:41:11 by dbolilyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTGKRELLM_CLASS_HPP
# define FTGKRELLM_CLASS_HPP

# include "gkrellmDef.hpp"
# include "NcurDisplay.class.hpp"
# include "GraficDisplay.class.hpp"

class FtGkrellm
{
	private:
		GraficDisplay	*_graph;
		NcurDisplay		*_ncur;
	public:
		FtGkrellm(void);
		FtGkrellm(FtGkrellm const &other);
		virtual ~FtGkrellm();
		FtGkrellm & operator=(FtGkrellm const &);

		void	runNcur(void);
		void	runSDL(void);

		GraficDisplay *getGraph() const;

		NcurDisplay *getNcur() const;
};




#endif
