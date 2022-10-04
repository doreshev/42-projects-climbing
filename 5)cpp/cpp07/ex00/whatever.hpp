/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:02:23 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/19 11:09:00 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template<typename T>
void	swap(T & a, T & b)
{
	T	tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template<typename T2>
T2 const & min(T2 const & a, T2 const & b)
{
	if (a < b)
		return (a);
	return (b);
}

template<typename T3>
T3 const & max(T3 const & a, T3 const & b)
{
	if (a > b)
		return (a);
	return (b);
}

#endif