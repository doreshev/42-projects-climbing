/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 19:02:47 by doreshev          #+#    #+#             */
/*   Updated: 2022/08/30 12:00:37 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	ft_check_edges(char *s, t_data *a)
{
	int	i;

	i = 0;
	while (s[i] && s[i] == ' ')
		i++;
	if (s[i] != '1')
		ft_error("Invalid Map!\n", a);
	while (s[i] == ' ' || s[i] == '1')
		i++;
	if (s[i] && s[i] != '\n')
		ft_error("Invalid Map!\n", a);
}

void	put_doors_and_keys(char *s, char *s2, char *s3, t_data *a)
{
	int	i;

	i = a->side;
	if (s2[i - 1] == ' ' || s2[i + 1] == ' ' || !s2[i + 1]
		|| s2[i + 1] == '\n' || s[i + 1] == '\n' || !s[i + 1]
		|| s[i - 1] == ' ' || s[i + 1] == ' ' || s[i] == ' '
		|| s3[i - 1] == ' ' || s3[i + 1] == ' ' || s3[i] == ' '
		|| s3[i + 1] == '\n' || !s3[i + 1])
		ft_error("Invalid Map!\n", a);
	if (s2[i] == '0' && s2[i + 1] == '1' && s2[i - 1] == '1'
		&& s[i] == '0' && s3[i] == '0' && (s[i + 1] == '1' || s3[i + 1] == '1'))
		s2[i] = 'D';
	else if (a->key_num == '0' && s2[i] == '0' && s2[i - 1] == '0'
		&& s2[i + 1] == '0' && s[i - 1] == '0' && s[i] == '0' && s[i + 1] == '0'
		&& s3[i] == '0' && s3[i + 1] == '0' && s3[i - 1] == '0')
	{
		a->key_num = '1';
		s2[i] = 'K';
		a->s_px = i;
	}
}

void	ft_check_maplines(char *s, char *s2, char *s3, t_data *a)
{
	int	i;

	i = 0;
	while (s2[i] && s2[i] == ' ')
		i++;
	if (s2[i] != '1')
		ft_error("Invalid Map!\n", a);
	while (s2 && s2[i] && s2[i] != '\n')
	{
		while (s2[i] && (s2[i] == ' ' || s2[i] == '1'))
			i++;
		if (s2[i] && s2[i] != '\n')
		{
			a->side = i;
			put_doors_and_keys(s, s2, s3, a);
			i++;
		}
	}
}

void	ft_map_check(t_list	*tmp, t_data *a)
{
	t_list	*tmp2;
	t_list	*tmp3;

	tmp2 = tmp->next;
	if (!tmp2)
		ft_error("Invalid Map!\n", a);
	tmp3 = tmp2->next;
	while (tmp2)
	{
		if (tmp == a->map)
			ft_check_edges(tmp->content, a);
		if (tmp3 == NULL)
		{
			ft_check_edges(tmp2->content, a);
			return ;
		}
		ft_check_maplines(tmp->content, tmp2->content, tmp3->content, a);
		tmp = tmp->next;
		tmp2 = tmp2->next;
		tmp3 = tmp3->next;
		if (a->key_num == '0')
			a->s_py++;
	}
}
