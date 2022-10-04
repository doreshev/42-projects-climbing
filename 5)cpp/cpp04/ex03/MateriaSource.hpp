/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:16:40 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/21 16:49:25 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	protected:
		AMateria*		_inventory[4];

	public:
		MateriaSource();
		MateriaSource(const MateriaSource & other);
		~MateriaSource();

		MateriaSource &	operator=(const MateriaSource & other);

		void learnMateria(AMateria* m);
		AMateria* createMateria(std::string const & type);
};

#endif