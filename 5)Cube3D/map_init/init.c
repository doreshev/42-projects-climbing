/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 12:45:23 by doreshev          #+#    #+#             */
/*   Updated: 2022/08/06 14:52:46 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	ft_map_process(t_data *a, char *argv)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_error("No such file or directory!\n", a);
	a->line = get_next_line(fd);
	if (!a->line)
		ft_error("Invalid map!\n", a);
	while (a->line)
	{
		ft_check_parameters(a, a->line, fd);
		if (!a->line)
			break ;
		free(a->line);
		a->line = get_next_line(fd);
	}
	close(fd);
	if (a->map == NULL)
		ft_error("Map pattern not found in file!\n", a);
}
