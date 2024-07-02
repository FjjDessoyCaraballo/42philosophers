/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:13:46 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/07/02 12:47:05 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	struct_init(t_data **data, t_overseer *overseer, char **argv)
{
	int	i;

	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		data[i] = malloc(sizeof(t_data));
		if (!data[i])
			return (0);
		memset(overseer, 0, sizeof(t_overseer));
		memset((*data), 0, sizeof(t_data));
		i++;
	}
	data[i] = NULL;
	if (struct_filler(data, overseer, argv) == 0
		|| init_locks(overseer, data) == 0)
		return (0);
	return (1);
}

int	struct_filler(t_data **data, t_overseer *overseer, char **argv)
{
	int	i;

	if (overseer_filler(overseer, argv) == 0)
		return (0);
	i = 0;
	while (i < overseer->no_of_philo)
	{
		data[i]->times_eaten = 0;
		data[i]->philo_id = i + 1;
		data[i]->overseer = overseer;
		data[i]->right_fork = malloc(sizeof(t_mtx));
		if (!data[i]->right_fork)
			return (0);
		pthread_mutex_init(data[i]->right_fork, NULL);
		i++;
	}
	fork_me(data, overseer);
	overseer->data = data;
	return (1);
}

int	fork_me(t_data **data, t_overseer *overseer)
{
	int	i;

	i = 0;
	while (i < overseer->no_of_philo)
	{
		if (overseer->no_of_philo == 1)
			data[i]->left_fork = NULL;
		if (i == 0)
			data[i]->left_fork = data[overseer->no_of_philo - 1]->right_fork;
		else
			data[i]->left_fork = data[i - 1]->right_fork;
		i++;
	}
	return (1);
}

int	overseer_filler(t_overseer *overseer, char **argv)
{
	overseer->no_of_philo = ft_atoi(argv[1]);
	overseer->death_time = ft_atoi(argv[2]);
	overseer->feed_time = ft_atoi(argv[3]);
	overseer->sleep_time = ft_atoi(argv[4]);
	if (argv[5])
		overseer->times_to_eat = ft_atoi(argv[5]);
	if (!argv[5])
		overseer->times_to_eat = INT_MAX;
	overseer->can_i_print = 0;
	overseer->death_flag = 0;
	overseer->meal_flag = 0;
	overseer->mic_lock = malloc(sizeof(t_mtx));
	if (!overseer->mic_lock)
		return (0);
	overseer->death_lock = malloc(sizeof(t_mtx));
	if (!overseer->death_lock)
		return (0);
	overseer->meal_lock = malloc(sizeof(t_mtx));
	if (!overseer->meal_lock)
		return (0);
	return (1);
}

int	init_locks(t_overseer *overseer, t_data **data)
{
	if (pthread_mutex_init(overseer->mic_lock, NULL) != 0)
		nuka_cola(ERR_MUTEX, overseer, data);
	if (pthread_mutex_init(overseer->death_lock, NULL) != 0)
		nuka_cola(ERR_MUTEX, overseer, data);
	if (pthread_mutex_init(overseer->meal_lock, NULL) != 0)
		nuka_cola(ERR_MUTEX, overseer, data);
	return (1);
}
