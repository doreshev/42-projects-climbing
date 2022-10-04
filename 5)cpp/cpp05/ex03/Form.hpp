/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:18:49 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/24 15:04:53 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	public:
		Form(void);
		Form(std::string name, int sign, int execute);
		Form(const Form & fixed);
		virtual ~Form(void);

		Form & operator=(const Form & other);

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

		class GradeTooLowExecException : public std::exception {
			public:
				virtual const char *what() const throw()
				{
					return ("Grade is too low for execution!");
				}
		};

		class GradeNotSignedException : public std::exception {
			public:
				virtual const char *what() const throw()
				{
					return ("Form is not signed!");
				}
		};

		std::string			getName(void) const;
		bool				getIssigned(void) const;
		int					getSign(void) const;
		int					getExecute(void) const;
		void				beSigned(Bureaucrat & i);

		virtual bool		execute(Bureaucrat const & executor) const = 0;

	private:
		const std::string		_name;
		bool					_issigned;
		const int				_sign;
		const int				_execute;
};

std::ostream &	operator<<(std::ostream & o, Form const & other);

#endif