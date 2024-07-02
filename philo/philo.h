/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:43:13 by lstorey           #+#    #+#             */
/*   Updated: 2024/07/02 11:49:48 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/* libraries */
# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>

/* defines */
# define MAX_PHILOS 200
# define INT_MAX 2147483646
# define ERR_TIME "Time collection failed"
# define ERR_MUTEX "Mutex failure"
# define ERR_MIC "Output failure"

/* structs */
typedef pthread_mutex_t	t_mtx;
typedef struct s_data	t_data;

typedef struct s_overseer
{
	int					no_of_philo;
	size_t				death_time;
	size_t				feed_time;
	size_t				sleep_time;
	t_data				**data;
	int					times_to_eat;
	int					death_flag;
	int					meal_flag;
	int					can_i_print;
	size_t				start_time;
	t_mtx				*meal_lock;
	t_mtx				*death_lock;
	t_mtx				*mic_lock;
}	t_overseer;

typedef struct s_data
{
	pthread_t			p_thread;
	int					times_eaten;
	size_t				start_time;
	size_t				last_time_eaten;
	int					philo_id;
	t_overseer			*overseer;
	t_mtx				*right_fork;
	t_mtx				*left_fork;
}	t_data;

/*					philo.c							*/
void		philosophize(t_data **data, t_overseer *overseer);
void		*dinner_for_x(void *data);
int			monitoring(t_overseer *os);
int			dinner_for_one(t_data *data, t_overseer *overseer);

/*					printer.c						*/
void		ft_putstr_fd(char *str, int fd);
int			microphone(t_data *data, t_overseer *overseer, char *action);

/*					routine.c						*/
int			dying(t_overseer *overseer, t_data *data);
int			full_belly(t_overseer *overseer, t_data **data);
int			check_flags(t_overseer *overseer);
int			eat_pray_love(t_data *data, t_overseer *overseer);
int			try_pick_fork(t_data *data, t_overseer *overseer);

/*					parsing.c						*/
int			parsing(char **argv);
int			no_characters(char **argv);

/*					utils.c							*/
int			ft_atoi(const char *str);
size_t		what_time_is_it(void);
void		nuka_cola(char *str, t_overseer *overseer, t_data **data);
void		clearing(t_data **data, t_overseer *overseer);
void		ft_usleep(size_t milisecs, t_overseer *overseer);

/*					struct_utils.c					*/
int			struct_filler(t_data **data, t_overseer *overseer, char **argv);
int			struct_init(t_data **data, t_overseer *overseer, char **argv);
int			fork_me(t_data **data, t_overseer *overseer);
int			overseer_filler(t_overseer *overseer, char **argv);
int			init_locks(t_overseer *overseer, t_data **data);

#endif
