/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:02:23 by doreshev          #+#    #+#             */
/*   Updated: 2022/10/03 13:08:41 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>

class	Span {
	public:
		Span(void);
		Span(unsigned int n);
		Span(const Span & other);
		~Span(void);

		Span & operator=(const Span & other);

		void		addNumber(int num);
		void		addNumber(std::vector<int> vector);
		int			shortestSpan(void);
		int			longestSpan(void);

	protected:
		unsigned int		_n;
		std::vector<int>	_arr;

};

#endif