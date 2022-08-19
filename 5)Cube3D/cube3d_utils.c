/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 12:44:15 by doreshev          #+#    #+#             */
/*   Updated: 2022/08/19 12:06:33 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_lstfree(t_list *map)
{
	t_list	*n1;

	if (!map)
		return ;
	n1 = map;
	while (map)
	{
		if (n1->content)
			free(n1->content);
		n1->content = NULL;
		n1 = n1->next;
		free(map);
		map = n1;
	}
}

void	ft_free(t_data *a)
{
	if (a->map)
		ft_lstfree(a->map);
	a->map = NULL;
	if (a->line)
		free(a->line);
	a->line = NULL;
	if (a->mlx)
		free(a->mlx);
	a->mlx = NULL;
	if (a->img)
		free(a->img);
	a->img = NULL;
	free(a->no);
	free(a->ea);
	free(a->we);
	free(a->so);
}

void	ft_error(char *s, t_data *a)
{
	ft_free(a);
	write(2, "Error\n", 6);
	ft_putstr_fd(s, 2);
	exit(EXIT_FAILURE);
}

int	ft_close(t_data *a)
{
	mlx_destroy_window(a->mlx, a->win);
	ft_lstfree(a->map);
	free(a->mlx);
	// system("leaks cube3d");
	exit(EXIT_SUCCESS);
}
