/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:38:07 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/13 13:29:03 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"

Phonebook::Phonebook(void)
{
	this->index = 0;
	return ;
}

Phonebook::~Phonebook(void)
{
	return ;
}

void	Phonebook::ft_add(void)
{
	int		index;

	index = this->index;
	if (index > 7)
		index = this->index % 8;
	this->contact[index].set_contact(index);
	this->index++;
	return ;
}

void	Phonebook::ft_search(void)
{
	std::string line;
	int			i;

	if (this->index == 0)
	{
		std::cout << "No Contacts Found on the Device!\n";
		return ;
	}
	this->ft_display_contacts();
	std::cout << "SEARCH: ";
	std::getline(std::cin, line);
	if (std::isdigit(line[0]) && line.length() == 1)
	{
		i = std::atoi(line.c_str());
		if (i >= this->index || i > 7)
			std::cout << "Contact not found!\n";
		else
		{
			std::cout << "First Name: " << this->contact[i].get_fname() << std::endl;
			std::cout << "Last Name: " << this->contact[i].get_lname() << std::endl;
			std::cout << "Nickname: " << this->contact[i].get_nickname() << std::endl;
			std::cout << "Phone Number: " << this->contact[i].get_phone() << std::endl;
			std::cout << "Darkest Secret: " << this->contact[i].get_secret() << std::endl;
		}
	}
	else
		std::cout << "Contact not found!\n";
}

static void ft_print_contacts(std::string s)
{
	int	i;
	int	k;

	std::cout << "|";
	i = s.length();
	if (i > 10)
	{
		for(k = 0; k < 9; k++)
			std::cout << s[k];
		std::cout << ".";
	}
	else
	{
		std::cout << s;
		while (i < 10)
		{
			std::cout << " ";
			i++;
		}
	}
}

void	Phonebook::ft_display_contacts(void)
{
	int	j;

	std::cout << "|Index     |First Name|Last Name |Nickname  |\n";
	j = 0;
	while(j < this->index && j < 8)
	{
		ft_print_contacts(this->contact[j].get_id());
		ft_print_contacts(this->contact[j].get_fname());
		ft_print_contacts(this->contact[j].get_lname());
		ft_print_contacts(this->contact[j].get_nickname());
		std::cout << "|" << std::endl;
		j++;
	}
}
