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

#ifndef CONVERSION_HPP
# define CONVERSION_HPP

# define STRING	    0
# define CHAR  	    2
# define INT   	    3
# define DOUBLE		4

# include <iostream>

class Conversion {
	public:
		Conversion(void);
		Conversion(char* value);
		Conversion(const Conversion & fixed);
		~Conversion(void);

		Conversion & operator=(const Conversion & other);

		class ConversionImpossible : public std::exception {
			public:
				virtual const char *what() const throw()
				{
					return ("impossible");
				}
		};

		class CharNonDisplayable : public std::exception {
			public:
				virtual const char *what() const throw()
				{
					return ("Non diplayable");
				}
		};
		

		std::string				getValue(void) const;
		int						getType(void) const;

		char					getChar(void) const;
		int						getInt(void) const;
		float					getFloat(void) const;
		double					getDouble(void) const;
		bool					printNan( void ) const;

	private:
		std::string		_value;
		int				_type;
		void			setType(void);
};

#endif