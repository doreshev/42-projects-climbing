/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:11:50 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/19 12:25:14 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	public:
		FragTrap(const std::string name);
		FragTrap(const FragTrap & fixed);
		~FragTrap(void);

		FragTrap & operator=(const FragTrap & other);
		void	highFivesGuys(void);

	private:
		FragTrap(void);
};

#endif