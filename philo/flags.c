/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:30:49 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/07/02 15:03:07 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_full_flag(t_overseer *overseer)
{
	pthread_mutex_lock(overseer->meal_lock);
	if (overseer->meal_flag == 1)
	{
		pthread_mutex_unlock(overseer->meal_lock);
		return (0);
	}
	pthread_mutex_unlock(overseer->meal_lock);
	return (1);
}

int	check_death_flag(t_overseer *overseer)
{
	pthread_mutex_lock(overseer->death_lock);
	if (overseer->death_flag == 1)
	{
		pthread_mutex_unlock(overseer->death_lock);
		return (0);
	}
	pthread_mutex_unlock(overseer->death_lock);
	return (1);
}
