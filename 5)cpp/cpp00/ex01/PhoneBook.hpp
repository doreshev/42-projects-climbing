/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 13:15:37 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/12 17:53:06 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class Phonebook {
	public:
		Phonebook(void);
		~Phonebook(void);
		int		index;
		void	ft_add(void);
		void	ft_search(void);
	private:
		Contact	contact[8];
		void	ft_display_contacts(void);
};

#endif