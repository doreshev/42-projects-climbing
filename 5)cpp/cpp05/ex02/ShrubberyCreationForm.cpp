/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 18:39:59 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/24 15:07:40 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : Form("ShrubberyCreationForm", 25, 5), _target("nothing")
{
	// std::cout << "ShrubberyCreationForm Default Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 25, 5), _target(target)
{
	// std::cout << "ShrubberyCreationForm Constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	// std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & other)
{
	// std::cout << "ShrubberyCreationForm Copy constructor called" << std::endl;
	*this = other;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm & other)
{
	// std::cout << "ShrubberyCreationForm Copy assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
	this->_target = other.getTarget();
	Form::operator=(other);
	return (*this);
}

std::string	ShrubberyCreationForm::getTarget(void) const
{
	return(this->_target);
}

void	drawTree(std::string name)
{
	std::ofstream		ofs;

	ofs.open(name.append("_shrubbery"));
	if (ofs.fail())
	{
		std::cerr << "Error: Can't create the file!" << std::endl;
		return ;
	}
	ofs << "              v .   ._, |_  .,\n";
	ofs << "           `-._\\/  .  \\ /    |/_\n";
	ofs << "               \\\\  _\\, y | \\//\n";
	ofs << "         _\\_.___\\\\, \\\\/ -.\\||\n";
	ofs << "           `7-,--.`._||  / / ,\n";
	ofs << "           /'     `-. `./ / |/_.'\n";
	ofs << "                     |    |//\n";
	ofs << "                     |_    /\n";
	ofs << "                     |-   |\n";
	ofs << "                     |   =|\n";
	ofs << "                     |    |\n";
	ofs << "--------------------/ ,  . \\--------._\n";
	ofs << "\n";
	ofs << "\n";
	ofs << "       _-_\n";
	ofs << "    /~~   ~~\\\n";
	ofs << " /~~         ~~\\\n";
	ofs << "{               }\n";
	ofs << " \\  _-     -_  /\n";
	ofs << "   ~  \\\\ //  ~\n";
	ofs << "_- -   | | _- _\n";
	ofs << "  _ -  | |   -_\n";
	ofs << "      // \\\\\n";
	ofs << std::endl;
	ofs.close();
}

bool	ShrubberyCreationForm:: execute(Bureaucrat const & executor) const
{
	if (this->getIssigned() == false)
		throw GradeNotSignedException();
	else if (executor.getGrade() > this->getExecute())
		throw GradeTooLowExecException();
	else
		drawTree(this->getTarget());
	return(true);
}