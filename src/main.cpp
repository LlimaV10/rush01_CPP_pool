/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolilyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 12:01:16 by dbolilyi          #+#    #+#             */
/*   Updated: 2019/04/14 12:01:17 by dbolilyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FtGkrellm.class.hpp"

int		main(int argc, char **argv)
{
	if (argc != 2 || strlen(argv[1]) != 1 ||
		(argv[1][0] != '0' && argv[1][0] != '1'))
	{
		std::cout << "usage: ft_gkrellm <0 - in Terminal || 1 - in Grafic window>" 
			<< std::endl;
		return 0;
	}
	FtGkrellm	gk;
	if (argv[1][0] == '0')
		gk.runNcur();
	else if (argv[1][0] == '1')
		gk.runSDL();
	return 0;
}
