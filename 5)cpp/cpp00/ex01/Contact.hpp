/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 13:30:56 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/12 17:46:54 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact {
	public:
		Contact(void);
		~Contact(void);
		void		set_contact(int id);
		std::string	get_id(void);
		std::string	get_fname(void);
		std::string	get_lname(void);
		std::string	get_nickname(void);
		std::string	get_phone(void);
		std::string	get_secret(void);
	private:
		std::string	_id;
		std::string	_fname;
		std::string	_lname;
		std::string	_nickname;
		std::string	_phone;
		std::string	_secret;
};

#endif