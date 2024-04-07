/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 10:49:51 by bwach             #+#    #+#             */
/*   Updated: 2024/04/06 17:30:59 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

void	forks_init(t_philo *philo, int i, int nb_philos)
{
	philo->fork1 = i;
	philo->fork2 = (i + 1) % nb_philos;
	if (philo->id % 2)
	{
		philo->fork1 = (i + 1) % nb_philos;
		philo->fork2 = i;
	}
}

//alloue de la memoire heaps pour chaque philo (avec leurs propres ressources)
int	philo_struct_init(t_scene *scene)
{
	int	i;

	i = 0;
	while (i < scene->nb_philos)
	{
		scene->philos[i] = (t_philo *)malloc(sizeof(t_philo));
		if (!scene->philos[i])
			return (0);
		scene->philos[i]->scene = scene;
		scene->philos[i]->id = i + 1;
		scene->philos[i]->nb_meal = 0;
		scene->philos[i]->time_lastmeal = 0;
		scene->philos[i]->time_ofdeath = scene->die_time;
		forks_init(scene->philos[i], i, scene->nb_philos);
		if (pthread_create(&scene->philos[i]->p, NULL,
				philo_life, (void *)scene->philos[i]))
			return (0);
		i++;
	}
	scene->philos[i] = NULL;
	return (1);
}

//alloue de la memoire heaps pour les mutex
int	mutex_init(t_scene *scene)
{
	int	i;

	i = 0;
	scene->fork_mutex = (pthread_mutex_t *)malloc(scene->nb_philos
			* sizeof(pthread_mutex_t));
	if (!scene->fork_mutex)
		return (0);
	while (i < scene->nb_philos)
	{
		pthread_mutex_init(&scene->fork_mutex[i], NULL);
		i++;
	}
	return (-1);
}

//alloue et check si struct philo
int	philo_init(t_scene *scene)
{
	scene->philos = (t_philo **)malloc((scene->nb_philos + 1)
			* sizeof(t_philo *));
	if (!scene->philos)
		return (0);
	if (pthread_create(&scene->monitor, NULL, ft_control, (void *)scene))
		return (0);
	if (!philo_struct_init(scene))
		return (0);
	return (1);
}
