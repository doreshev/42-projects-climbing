/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 10:43:49 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/26 12:28:11 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

int main()
{
	Data	*a = new Data("Hello!");
	uintptr_t	b;
	Data	*c;
	
	std::cout << "Initial Data value on declaration >> " << a->getValue() << std::endl;
	std::cout << "Initial Data pointer address on declaration >> "  << a << std::endl << std::endl;

	std::cout << "* Serializing Initial Data pointer *" << std::endl;
	b = serialize(a);

	std::cout << "Serialized pointer address >> " << &b << std::endl << std::endl;

	std::cout << "* Deserializing to New Data pointer *" << std::endl;
	c = deserialize(b);

	std::cout << "New Data pointer address >> " << c << std::endl;
	std::cout << "Initial Data pointer address >> "  << a << std::endl << std::endl;

	std::cout << "New Data pointer value >> " << c->getValue() << std::endl;
	std::cout << "Initial Data pointer value >> " << a->getValue() << std::endl << std::endl;

	delete a;
	return (0);
}
