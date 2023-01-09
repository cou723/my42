/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 15:12:06 by *******           #+#    #+#             */
/*   Updated: 2023/01/09 11:51:32 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# define USAGE "Usage: ./philo [number_of_philosophers] [time_to_die] \
[time_to_eat] [time_to_sleep] \
[number_of_times_each_philosopher_must_eat(optional)]"

# define PPAM_TAKE_FORK "has taken a fork"
# define PPAM_RELEASE_FORK "has released a fork"
# define PPAM_EAT "is eating"
# define PPAM_SLEEP "is sleeping"
# define PPAM_THINK "is thinking"
# define PPAM_DIE "died"

# include <pthread.h>
# include <stdbool.h>
# include <stddef.h>

typedef unsigned int	t_id;
typedef long long		t_msec;
typedef long long		t_usec;
typedef bool			t_false;
typedef struct s_philo
{
	t_id				id;
	t_id				left_fork;
	t_id				right_fork;
	t_msec				last_eat;
	pthread_mutex_t		last_eat_mutex;
	size_t				eat_count;
	pthread_mutex_t		eat_count_mutex;
	pthread_t			pthread;
	t_msec				time_to_die;
	t_msec				time_to_eat;
	t_msec				time_to_sleep;
}						t_philo;

typedef struct s_table
{
	size_t				num_of_philo;
	size_t				act_limit;
	t_philo				philos[256];
	pthread_mutex_t		forks[256];
	pthread_mutex_t		exist_dead_mutex;
	bool				exist_dead;
	pthread_t			philo_monitor;
	t_msec				start_time;
}						t_table;

typedef struct s_routine_param
{
	t_table				*table;
	t_philo				*philo;
}						t_routine_param;

// main process
bool					is_correct_args(int argc, char *argv[]);
void					*philo(void *param);
void					*philo_monitor(void *void_param);
void					display_philo_action(t_table *table, t_id id,
							char *message);
bool					init(t_table *table, int argc, char *argv[]);

// eating
bool					take_forks(t_table *table, t_philo *philo);
void					eat_spaghetti(t_table *table, t_philo *philo);
void					release_forks(pthread_mutex_t *forks, t_philo *philo);

// ft*
long int				ft_atoli(const char *nptr);
size_t					ft_strlen(const char *str);

// utils
t_msec					get_time(void);
t_usec					get_current_utime(void);
void					exact_usleep(t_usec usec);
void					exact_msleep(t_msec msec);
void					put_str(char *str);

void					destroy_philo(t_philo *philo);
void					destroy_philos(t_philo *philo, size_t count);
void					destroy_table_forks(t_table *table);
void					destroy_forks(pthread_mutex_t forks[], size_t count);

// init
bool					init_table(t_table *table, int argc, char *argv[]);

#endif /* PHILO_H */
