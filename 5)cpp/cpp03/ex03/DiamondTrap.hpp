/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:33:26 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/19 16:13:21 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
	public:
		DiamondTrap(const std::string name);
		DiamondTrap(const DiamondTrap & fixed);
		~DiamondTrap(void);

		DiamondTrap & operator=(const DiamondTrap & other);

		std::string		getName( void ) const;
		void			whoAmI(void);

	private:
		DiamondTrap(void);
		std::string			_name;
};

#endif