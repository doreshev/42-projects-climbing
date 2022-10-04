/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 10:43:49 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/26 13:12:51 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"
#include <time.h>

int main()
{
	Base	*temp;

	srand(time(NULL));
	std::cout << "* Generating value *" << std::endl;
	temp = generate();

	std::cout << std::endl << "* Pointer test *" << std::endl;
	identify(temp);

	std::cout << std::endl << "* Reference test *" << std::endl;
	identify(*temp);

	delete temp;
	return (0);
}
