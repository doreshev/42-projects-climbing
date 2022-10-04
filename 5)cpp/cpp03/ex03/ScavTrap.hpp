/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:45:30 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/19 15:49:59 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap {
	public:
		ScavTrap(const std::string name);
		ScavTrap(const ScavTrap & fixed);
		~ScavTrap(void);

		ScavTrap & operator=(const ScavTrap & other);
		void	guardGate(void);
		void	attack(const std::string & target);

	protected:
		ScavTrap(void);
};

#endif