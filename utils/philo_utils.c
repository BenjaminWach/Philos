/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 22:35:03 by bwach             #+#    #+#             */
/*   Updated: 2024/04/07 10:55:02 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

void	philo_lonely(t_scene *scene, t_philo *philo)
{
	pthread_mutex_lock(&scene->fork_mutex[philo->fork1]);
	printf("0 1 has taken a fork\n");
	timeto_sleep((scene->die_time + 1) * 1e3);
	printf("%d %d has died\n", ft_gettime() - scene->start, philo->id);
	exit (0);
}

int	ft_letemcook(t_scene *scene)
{
	int	i;

	i = 0;
	scene->is_running = 1;
	while (i < scene->nb_philos)
	{
		if (pthread_join(scene->philos[i]->p, NULL) != 0)
			return (0);
		i++;
	}
	scene->is_running = 0;
	if (pthread_join(scene->philos[i]->p, NULL))
		return (0);
	return (1);
}

void	*philo_life(void *arg)
{
	t_philo	*philo;
	t_scene	*scene;

	philo = (t_philo *)arg;
	scene = philo->scene;
	while (!scene->is_running)
	{
	}
	if (philo->id % 2)
		timeto_sleep(100);
	if (scene->nb_meals == 0)
		return (NULL);
	while (simulation_is_on(scene))
	{
		if (simulation_is_on(scene))
			philo_eat(scene, philo);
		if (scene->nb_meals != -1 && scene->nb_meals == philo->nb_meal)
			break ;
		if (simulation_is_on(scene))
			philo_sleep(scene, philo);
		if (simulation_is_on(scene))
			philo_think(scene, philo);
	}
	return (NULL);
}
