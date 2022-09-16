/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:44:30 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/12 17:53:37 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	Phonebook	p_book;
	std::string	line;
	bool		j;

	j = true;
	while (j == true)
	{
		std::cout << "PHONEBOOK: ";
		std::getline(std::cin, line);
		if (line.compare("ADD") == 0)
			p_book.ft_add();
		else if (line.compare("SEARCH") == 0)
			p_book.ft_search();
		else if (line.compare("EXIT") == 0)
			j = false;
	}
	return (0);
}
