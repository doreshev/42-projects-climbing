/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:02:23 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/19 11:09:00 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "Form.hpp"

class	Form;

class	Bureaucrat {
	public:
		Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat & fixed);
		~Bureaucrat(void);

		Bureaucrat & operator=(const Bureaucrat & other);

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw()
				{
					return ("Grade is too low!");
				}
		};

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw()
				{
					return ("Grade is too high!");
				}
		};

		std::string			getName(void) const;
		int					getGrade(void) const;
		void				incrGrade(void);
		void				decrGrade(void);

		void				signForm(Form & i);

	private:
		const std::string		_name;
		int						_grade;
};

std::ostream &	operator<<(std::ostream & o, Bureaucrat const & other);

#endif