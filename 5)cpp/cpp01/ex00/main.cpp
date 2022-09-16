/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 10:43:49 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/14 11:50:34 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie*	s;

	s = newZombie("Franky");
	std::cout << "Trying to talk to " << s->getname() << std::endl;
	s->announce();
	delete s;
	randomChump("Stein");
	return (0);
}
