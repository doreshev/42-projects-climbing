/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 18:40:29 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/24 15:07:59 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"

class RobotomyRequestForm : public Form{
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm & fixed);
		~RobotomyRequestForm(void);

		RobotomyRequestForm & operator=(const RobotomyRequestForm & other);

		bool				execute(Bureaucrat const & executor) const;
		std::string			getTarget(void) const;

	private:
		std::string				_target;
};

#endif