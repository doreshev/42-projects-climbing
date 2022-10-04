/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:16:02 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/26 13:08:03 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IDENTIFY_HPP
# define IDENTIFY_HPP

# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif