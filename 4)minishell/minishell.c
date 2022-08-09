/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 13:32:06 by doreshev          #+#    #+#             */
/*   Updated: 2022/07/27 15:51:14 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	a;

	if (argc == 1)
	{
		a.argv0 = argv[0];
		a.env1 = envp;
		ft_init(&a);
		rl_redisplay();
		write(1, "exit\n", 5);
		ft_free(&a, 0);
	}
	return (0);
}
