/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:02:23 by doreshev          #+#    #+#             */
/*   Updated: 2022/10/03 17:50:24 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template<typename T>
class	MutantStack : public std::stack<T> {
	public:
		MutantStack(void) : std::stack<T>(){}
		MutantStack(const MutantStack & other) : std::stack<T>(other) {}
		~MutantStack(void) {}

		MutantStack & operator=(const MutantStack & other) {
			if (this == &other)
				return (*this);
			std::stack<T>::operator=(other);
			return (*this);
		}

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;

		iterator	begin(void) {
			return (this->c.begin());
		}
		iterator	end(void) {
			return (this->c.end());
		}
		reverse_iterator	rbegin(void) {
			return (this->c.rbegin());
		}
		reverse_iterator	rend(void) {
			return (this->c.rend());
		}

};

#endif