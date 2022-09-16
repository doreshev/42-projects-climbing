/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 13:30:56 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/14 18:47:40 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie {
	public:
		Zombie(void);
		~Zombie(void);
		void	announce(void);
		void	setname(std::string	name);
		std::string	getname(void) const;
	private:
		std::string	_name;
};

Zombie* zombieHorde( int N, std::string name );

#endif