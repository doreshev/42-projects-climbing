/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:46:46 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/21 17:58:47 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AMateria.hpp"

class Character : public ICharacter
{
	protected:
		std::string		_name;
		AMateria*		_inventory[4];
		AMateria*		_floor[4];

	public:
		Character();
		Character(std::string name);
		Character(const Character & other);
		~Character();

		Character &	operator=(const Character & other);

		std::string const & getName() const;
		void	droponFloor(AMateria* m);
		void	equip(AMateria* m);
		void	unequip(int idx);
		void	use(int idx, ICharacter& target);
};

#endif