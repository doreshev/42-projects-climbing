/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 10:43:49 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/14 19:40:54 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>

std::string	ft_replace(char **argv, std::string result)
{
	std::string		s1;
	std::string		s2;
	int				len1;
	int				len2;

	s1 = argv[2];
	s2 = argv[3];
	if (!argv[2] || s1.compare("\0") == 0)
		return (result);
	len1 = s1.length();
	len2 = s2.length() - 1;
	for (int i = 0; result[i] != '\0'; i++)
	{
		if(result.substr(i, len1).compare(s1) == 0)
		{
			result = result.substr(0, i) + s2 + result.substr(i + len1);
			i += len2;
		}
	}
	return (result);
}

int main(int argc, char **argv)
{
	std::ifstream		ifs;
	std::ofstream		ofs;
	std::string			filename;
	std::string			result;
	std::ostringstream	buffer;

	if (argc == 4)
	{
		filename = argv[1];
		ifs.open(filename);
		if (ifs.fail())
		{
			std::cerr << "Error: Can't open the file!" << std::endl;
			return (1);
		}
		ofs.open(filename.append(".replace"));
		if (ofs.fail())
		{
			std::cerr << "Error: Can't create the file!" << std::endl;
			ifs.close();
			return (1);
		}
		buffer << ifs.rdbuf();
		result = ft_replace(argv, buffer.str());
		ofs << result;
		ifs.close();
		ofs.close();
	}
	else
		std::cerr << "Error: Incorrect number of parameters!" << std::endl;
	return (0);
}
