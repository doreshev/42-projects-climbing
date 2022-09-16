/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:19:19 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/13 12:54:31 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

void	Contact::set_contact(int id)
{
	this->_id = std::to_string(id);
	std::cout << "Enter First Name: ";
	std::getline(std::cin, this->_fname);
	while (this->_fname.length() == 0)
	{
		std::cout << "Field Can't Be Empty!\nEnter First Name: ";
		std::getline(std::cin, this->_fname);
	}
	std::cout << "Enter Last name: ";
	std::getline(std::cin, this->_lname);
	while (this->_lname.length() == 0)
	{
		std::cout << "Field Can't Be Empty!\nEnter Last Name: ";
		std::getline(std::cin, this->_lname);
	}
	std::cout << "Enter Nickname: ";
	std::getline(std::cin, this->_nickname);
	while (this->_nickname.length() == 0)
	{
		std::cout << "Field Can't Be Empty!\nEnter Nickname: ";
		std::getline(std::cin, this->_nickname);
	}
	std::cout << "Enter Phone Number: ";
	std::getline(std::cin, this->_phone);
	while (this->_phone.length() == 0)
	{
		std::cout << "Field Can't Be Empty!\nEnter Phone Number: ";
		std::getline(std::cin, this->_phone);
	}
	std::cout << "Enter Darkest Secret: ";
	std::getline(std::cin, this->_secret);
	while (this->_secret.length() == 0)
	{
		std::cout << "Field Can't Be Empty!\nEnter Darkest Secret: ";
		std::getline(std::cin, this->_secret);
	}
}

std::string	Contact::get_id(void)
{
	return(this->_id);
}

std::string	Contact::get_fname(void)
{
	return(this->_fname);
}

std::string	Contact::get_lname(void)
{
	return(this->_lname);
}

std::string	Contact::get_nickname(void)
{
	return(this->_nickname);
}

std::string	Contact::get_phone(void)
{
	return(this->_phone);
}

std::string	Contact::get_secret(void)
{
	return(this->_secret);
}