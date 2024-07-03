/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:26:25 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/07/03 10:42:18 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philosophize(t_data **data, t_overseer *overseer)
{
	int			i;

	i = 0;
	overseer->start_time = what_time_is_it();
	while (i < overseer->no_of_philo)
	{
		data[i]->last_time_eaten = overseer->start_time;
		data[i]->start_time = what_time_is_it();
		if (pthread_create(&data[i]->p_thread, NULL,
				&dinner_for_x, data[i]) != 0)
			nuka_cola("Thread creation failed\n", overseer, data);
		i++;
	}
	monitoring(overseer);
}

int	monitoring(t_overseer *os)
{
	int			index;

	ft_usleep(3, os);
	while (1)
	{
		index = 0;
		while (index < os->no_of_philo)
		{
			if (dying(os, os->data[index]) == 0
				|| full_belly(os, os->data) == 0)
				return (1);
			index++;
		}
	}
	return (1);
}

void	*dinner_for_x(void *data)
{
	t_data			*p_data;

	p_data = (t_data *)data;
	if (dinner_for_one(p_data, p_data->overseer) == 0)
		return (NULL);
	if (p_data->philo_id % 2 == 0)
	{
		microphone(p_data, p_data->overseer, "is thinking");
		ft_usleep(p_data->overseer->feed_time / 10, p_data->overseer);
	}
	pthread_mutex_lock(p_data->overseer->death_lock);
	while (p_data->overseer->death_flag != 1
		|| p_data->overseer->meal_flag != 1
		|| p_data->overseer->can_i_print != 1)
	{
		pthread_mutex_unlock(p_data->overseer->death_lock);
		if (eat_pray_love(p_data, p_data->overseer) == 0)
			break ;
	}
	return (NULL);
}

int	dinner_for_one(t_data *data, t_overseer *overseer)
{
	if (overseer->no_of_philo == 1)
	{
		ft_usleep(overseer->death_time, overseer);
		microphone(data, overseer, "died");
		return (0);
	}
	return (1);
}
