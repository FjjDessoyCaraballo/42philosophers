/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:56:51 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/07/03 11:51:49 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	full_belly(t_overseer *overseer, t_data **data)
{
	int	count;
	int	index;

	index = 0;
	count = 0;
	while (index < overseer->no_of_philo)
	{
		if (data[index]->times_eaten >= overseer->times_to_eat)
			count++;
		index++;
	}
	if (count >= overseer->no_of_philo)
	{
		pthread_mutex_lock(overseer->meal_lock);
		overseer->meal_flag = 1;
		pthread_mutex_unlock(overseer->meal_lock);
		return (0);
	}
	return (1);
}

int	dying(t_overseer *overseer, t_data *data)
{
	if (check_death_flag(overseer) == 0 || check_full_flag(overseer) == 0)
		return (0);
	if ((what_time_is_it() - data->last_time_eaten >= overseer->death_time)
		&& overseer->can_i_print == 0)
	{
		pthread_mutex_lock(overseer->death_lock);
		overseer->death_flag = 1;
		pthread_mutex_unlock(overseer->death_lock);
		microphone(data, overseer, "died");
		pthread_mutex_lock(overseer->mic_lock);
		overseer->can_i_print = 1;
		pthread_mutex_unlock(overseer->mic_lock);
		return (0);
	}
	if (check_death_flag(overseer) == 0 || check_full_flag(overseer) == 0)
		return (0);
	return (1);
}

int	eat_pray_love(t_data *data, t_overseer *overseer)
{
	if (check_death_flag(overseer) == 0 || check_full_flag(overseer) == 0)
		return (0);
	try_pick_fork(data, overseer);
	pthread_mutex_lock(overseer->meal_lock);
	data->last_time_eaten = what_time_is_it();
	pthread_mutex_unlock(overseer->meal_lock);
	if (microphone(data, overseer, "is eating") == 0)
	{
		pthread_mutex_unlock(data->right_fork);
		pthread_mutex_unlock(data->left_fork);
		return (0);
	}
	data->times_eaten += 1;
	ft_usleep(overseer->feed_time, overseer);
	pthread_mutex_unlock(data->left_fork);
	pthread_mutex_unlock(data->right_fork);
	if (microphone(data, overseer, "is sleeping") == 0)
		return (0);
	ft_usleep(overseer->sleep_time, overseer);
	if (microphone(data, overseer, "is thinking") == 0)
		return (0);
	if (check_death_flag(overseer) == 0 || check_full_flag(overseer) == 0)
		return (0);
	return (1);
}

int	try_pick_fork(t_data *data, t_overseer *overseer)
{
	int	i;

	while (1)
	{
		i = 0;
		if (!pthread_mutex_lock(data->right_fork))
		{
			i++;
			if (microphone(data, overseer, "has taken a fork") == 0)
				return (0);
		}
		if (!pthread_mutex_lock(data->left_fork))
			i++;
		if (i == 2)
		{
			if (microphone(data, overseer, "has taken a fork") == 0)
				return (0);
			return (1);
		}
		else
			ft_usleep(100, overseer);
	}
	return (0);
}
