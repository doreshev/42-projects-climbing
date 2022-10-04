/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 10:43:49 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/21 10:57:24 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j;//should not create a leak
		delete i;
	}
	{
		Animal *k[8];
		
		int i = 0;
		for (; i < 4; i++)
			k[i] = new Dog();
		for (; i < 8; i++)
			k[i] = new Cat();
		for (; i > 0; i--)
		{
			std::cout << "I'm  animal number " << i;
			std::cout << " and I'm a " << k[i- 1]->getType() << std::endl;
			delete k[i - 1];
		}
	}
	{
		const Dog *Bethoven = new Dog();
		Bethoven->makeSound();
		std::cout << "I'm a " << Bethoven->getType() << std::endl;
		std::cout << "My thoughts is -> " << Bethoven->getIdea(0) << std::endl;
		delete Bethoven;
		const Cat *Simba = new Cat();
		Simba->makeSound();
		std::cout << "I'm a " << Simba->getType() << std::endl;
		std::cout << "My thoughts is -> " << Simba->getIdea(0) << std::endl;
		delete Simba;
	}
	return (0);
}
