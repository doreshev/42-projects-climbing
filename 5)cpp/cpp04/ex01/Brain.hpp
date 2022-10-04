/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:42:00 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/20 19:06:48 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain {
	public:
		Brain(void);
		Brain(const Brain & other);
		virtual ~Brain(void);

		Brain & operator=( const Brain & other );
		void		setIdea( std::string idea,  int index );
		const std::string & getIdea(int index) const;

	protected:
		std::string		_idea[100];
};

#endif