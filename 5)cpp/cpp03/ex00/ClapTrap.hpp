/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:02:23 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/19 11:09:00 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap {
	public:
		ClapTrap(const std::string name);
		ClapTrap(const ClapTrap & fixed);
		~ClapTrap(void);

		ClapTrap & operator=(const ClapTrap & other);

		std::string		getName( void ) const;
		unsigned int	getHp( void ) const;
		unsigned int	getEnergy( void ) const;
		unsigned int	getDmg( void ) const;
		void			setName( const std::string name );
		void			setHp( unsigned int i );
		void			setEnergy( unsigned int i );
		void			setDmg( unsigned int i );

		void			attack(const std::string& target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);

	private:
		std::string			_name;
		unsigned int		_hp;
		unsigned int		_energy;
		unsigned int		_dmg;
		ClapTrap(void);
};

#endif