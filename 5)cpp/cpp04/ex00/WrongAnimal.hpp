/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:49:27 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/19 17:49:30 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal {
	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal & fixed);
		~WrongAnimal(void);

		WrongAnimal & operator=(const WrongAnimal & other);

		std::string		getType( void ) const;
		void			setType( const std::string name );
		void			makeSound(void) const;

	protected:
		std::string		_type;
};

#endif