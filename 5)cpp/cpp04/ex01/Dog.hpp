/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:48:39 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/20 19:04:03 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
	public:
		Dog(void);
		Dog(const Dog & fixed);
		~Dog(void);

		Dog & operator=(const Dog & other);

		void	makeSound(void) const;
		const std::string & getIdea(int index) const;

	private:
		Brain*		_brain;
};

#endif