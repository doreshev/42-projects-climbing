/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:48:56 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/20 19:05:20 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
	public:
		Cat(void);
		Cat(const Cat & other);
		~Cat(void);

		Cat & operator=(const Cat & other);
		void	makeSound(void) const;
		const std::string & getIdea(int index) const;

	private:
		Brain*		_brain;
};

#endif