/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 19:09:46 by doreshev          #+#    #+#             */
/*   Updated: 2022/06/20 19:41:45 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check(int argc, char **argv)
{
	if (ft_atoi(argv[2]) < 0 || ft_atoi(argv[3]) < 0 || ft_atoi(argv[4]) < 0
		|| ft_atoi(argv[1]) < 0)
	{
		printf("Wrong input parameters!\n");
		return (0);
	}
	if (argc == 6 && ft_atoi(argv[5]) < 1)
		return (0);
	if (ft_atoi(argv[1]) > 0 && ft_atoi(argv[2]) == 0)
	{
		printf("0ms 1 died!\n");
		return (0);
	}
	if (ft_atoi(argv[1]) == 1)
	{
		printf("0ms 1 has taken a fork\n");
		printf("%ims 1 died!\n", ft_atoi(argv[2]));
		return (0);
	}
	return (ft_atoi(argv[1]));
}

int	ft_initialize_sub3(int argc, char **argv, t_data *data)
{
	struct timeval	*time1;

	time1 = malloc(sizeof(struct timeval) * 1);
	if (!time1 || gettimeofday(time1, 0) == -1)
		return (1);
	while (data)
	{
		data->last_eat = malloc(sizeof(struct timeval) * 1);
		if (!data->last_eat || gettimeofday(data->last_eat, 0) == -1)
			return (1);
		data->time = time1;
		data->t2d = ft_atoi(argv[2]);
		data->t2e = ft_atoi(argv[3]);
		data->t2s = ft_atoi(argv[4]);
		data->t2em = 0;
		if (argc == 6)
			data->t2em = ft_atoi(argv[5]);
		data = data->next;
	}
	return (0);
}

int	ft_initialize_sub2(t_data *data)
{
	sem_t	*in;
	sem_t	*sem;

	sem_unlink("/sem1");
	sem_unlink("/sem2");
	sem = sem_open("/sem1", O_CREAT, 0644, data->tot_ph);
	in = sem_open("/sem2", O_CREAT, 0644, 1);
	if (in == SEM_FAILED || sem == SEM_FAILED)
		return (1);
	while (data)
	{
		data->tid = malloc(sizeof(pthread_t) * 1);
		if (!data->tid)
			return (1);
		data->fork = sem;
		data->in = in;
		data = data->next;
	}
	return (0);
}

int	ft_initialize_sub(t_data *data, int k)
{
	t_data	*tmp;
	int		i;

	i = 0;
	while (k > i++)
	{
		data->tot_ph = k;
		data->phn = i;
		if (k == i)
			break ;
		tmp = malloc(sizeof(t_data) * 1);
		if (!tmp)
			return (1);
		data->next = tmp;
		data = tmp;
	}
	data->next = NULL;
	return (0);
}

t_data	*ft_initialize(int argc, char **argv)
{
	int		k;
	t_data	*data;

	k = ft_check(argc, argv);
	if (k < 1)
		return (NULL);
	data = malloc(sizeof(t_data) * 1);
	if (!data)
		return (NULL);
	if (ft_initialize_sub(data, k))
	{
		ft_free(data);
		return (NULL);
	}
	if (ft_initialize_sub2(data))
	{
		ft_free(data);
		return (NULL);
	}
	if (ft_initialize_sub3(argc, argv, data))
	{
		ft_free(data);
		return (NULL);
	}
	return (data);
}
