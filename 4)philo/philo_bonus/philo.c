/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 17:29:29 by doreshev          #+#    #+#             */
/*   Updated: 2022/06/22 13:42:32 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_create_process(t_data *data)
{
	int	status;
	int	i;

	i = data->tot_ph;
	while (data)
	{
		data->pid = fork();
		if (data->pid < 0)
			return ;
		if (data->pid == 0)
			ft_child_process(data);
		data = data->next;
	}
	if (i == 0)
		i = 1;
	while (i > 0)
	{
		waitpid(-1, &status, 0);
		if (WEXITSTATUS(status) == 1)
			return ;
		i--;
	}
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc == 5 || argc == 6)
	{
		data = ft_initialize(argc, argv);
		if (data == NULL)
			return (1);
		ft_create_process(data);
		ft_free(data);
	}
	else
		printf("Wrong input parameters!\n");
	return (0);
}
