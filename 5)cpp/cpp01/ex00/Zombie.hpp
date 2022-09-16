/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 13:30:56 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/14 18:49:02 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie {
	public:
		Zombie(std::string	name);
		~Zombie(void);
		void announce(void);
		std::string	getname(void) const;
	private:
		std::string	_name;
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif