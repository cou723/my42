/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 15:12:33 by *******           #+#    #+#             */
/*   Updated: 2023/01/09 11:51:32 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <philo.h>
#include <pthread.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static t_false	free_params(t_routine_param **params, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free(params[i]);
		i++;
	}
	free(params);
	return (false);
}

static bool	start_thread(t_table *table)
{
	t_routine_param	**params;
	size_t			i;

	i = 0;
	params = malloc(sizeof(t_routine_param) * table->num_of_philo);
	if (params == NULL)
		return (false);
	while (i < table->num_of_philo)
	{
		params[i] = malloc(sizeof(t_routine_param));
		if (params[i] == NULL)
			return (free_params(params, i));
		params[i]->table = table;
		params[i]->philo = &(table->philos[i]);
		if (pthread_create(&table->philos[i].pthread, NULL, philo, params[i]))
			return (free_params(params, i));
		i++;
	}
	free(params);
	if (pthread_create(&table->philo_monitor, NULL, philo_monitor, table) != 0)
		return (false);
	return (true);
}

static void	end(t_table *table)
{
	size_t	i;

	i = -1;
	while (++i < table->num_of_philo)
		pthread_join(table->philos[i].pthread, NULL);
	pthread_join(table->philo_monitor, NULL);
	destroy_table_forks(table);
	destroy_philos(table->philos, table->num_of_philo);
	pthread_mutex_destroy(&table->exist_dead_mutex);
}

bool	init(t_table *table, int argc, char *argv[])
{
	if (!is_correct_args(argc, argv))
	{
		put_str(USAGE);
		return (false);
	}
	if (!init_table(table, argc, argv))
		return (false);
	table->start_time = get_time();
	if (pthread_mutex_init(&(table->exist_dead_mutex), NULL) == -1)
	{
		destroy_table_forks(table);
		destroy_philos(table->philos, table->num_of_philo);
		return (false);
	}
	return (true);
}

int	main(int argc, char *argv[])
{
	t_table	table;

	if (!init(&table, argc, argv))
		return (EXIT_FAILURE);
	if (!start_thread(&table))
	{
		destroy_table_forks(&table);
		return (EXIT_FAILURE);
	}
	end(&table);
	return (EXIT_SUCCESS);
}
