/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 18:40:44 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/24 15:08:07 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"

class PresidentialPardonForm : public Form{
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm & fixed);
		~PresidentialPardonForm(void);

		PresidentialPardonForm & operator=(const PresidentialPardonForm & other);

		bool				execute(Bureaucrat const & executor) const;
		std::string			getTarget(void) const;

	private:
		std::string				_target;
};

#endif