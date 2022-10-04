/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:52:35 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/17 16:45:31 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point {
	public:
		//	Constructors					//
		Point(void);
		Point(const float i, const float j);
		Point(Point const & fixed);
		~Point(void);

		//	Assignment operator				//
		Point &	operator=(Point const & other);

		//	Class member functions			//
		Fixed	getX( void ) const;
		void	setX( Fixed const num);
		Fixed	getY( void ) const;
		void	setY( Fixed const num);

	private:
		Fixed const		_x;
		Fixed const		_y;	
};

//	Overloaded insertion operator			//
bool	bsp( Point const a, Point const b, Point const c, Point const point);

#endif