/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 22:33:02 by bwach             #+#    #+#             */
/*   Updated: 2024/04/07 10:54:06 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"
/*
void	philo_eat(t_scene *scene, t_philo *philo)
{
	if (pthread_mutex_lock(&scene->fork_mutex[philo->fork1]) == 0)
	{
		if (scene->nb_philos < 2)
			philo_lonely(scene, philo);
		if (!simulation_is_on(scene))
			return ;
		printf("%d %d has taken a fork\n", ft_gettime() - scene->start,
			philo->id);
		if (pthread_mutex_lock(&scene->fork_mutex[philo->fork2]) == 0)
		{
			if (!simulation_is_on(scene))
				return ;
			philo->time_lastmeal = ft_gettime();
			printf("%d %d has taken a fork\n", (philo->time_lastmeal
					- scene->start), philo->id);
			printf("%d %d is eating\n", (philo->time_lastmeal
					- scene->start), philo->id);
			philo->nb_meal++;
			philo->time_ofdeath = philo->time_lastmeal
				-(scene->start + scene->die_time);
			timeto_sleep(scene->eat_time * 1e3);
			pthread_mutex_unlock(&scene->fork_mutex[philo->fork2]);
		}
		pthread_mutex_unlock(&scene->fork_mutex[philo->fork1]);
	}
}*/

static void	take_fork(t_scene *scene, t_philo *philo, int fork)
{
	if (pthread_mutex_lock(&scene->fork_mutex[fork]) == 0)
	{
		printf("%d %d has taken a fork\n", ft_gettime()
			- scene->start, philo->id);
	}
}

static void	eat(t_scene *scene, t_philo *philo)
{
	philo->time_lastmeal = ft_gettime();
	printf("%d %d is eating\n", (philo->time_lastmeal - scene->start),
		philo->id);
	philo->nb_meal++;
	philo->time_ofdeath = philo->time_lastmeal
		- (scene->start + scene->die_time);
	timeto_sleep(scene->eat_time * 1e3);
}

void	philo_eat(t_scene *scene, t_philo *philo)
{
	if (scene->nb_philos < 2)
		philo_lonely(scene, philo);
	take_fork(scene, philo, philo->fork1);
	if (!simulation_is_on(scene))
		return ;
	take_fork(scene, philo, philo->fork2);
	if (!simulation_is_on(scene))
		return ;
	eat(scene, philo);
	pthread_mutex_unlock(&scene->fork_mutex[philo->fork2]);
	pthread_mutex_unlock(&scene->fork_mutex[philo->fork1]);
}

void	philo_sleep(t_scene *scene, t_philo *philo)
{
	printf("%d %d is sleeping\n", ft_gettime() - scene->start,
		philo->id);
	timeto_sleep(scene->sleep_time * 1e3);
}

void	philo_think(t_scene *scene, t_philo *philo)
{
	printf("%d %d is thinking\n", ft_gettime()
		- scene->start, philo->id);
	if (scene->nb_philos % 2)
		timeto_sleep(100);
}
