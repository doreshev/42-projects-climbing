/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 10:43:49 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/14 18:48:39 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie*	Horde;
	int		i;
	int		N;

	N = 5;
	Horde = zombieHorde(N, "Eval Zombie");
	for (i = 0; i < N; i++)
	{
		Horde[i].announce();
	}
	delete [] Horde;
	return (0);
}
