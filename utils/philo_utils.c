/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 22:35:03 by bwach             #+#    #+#             */
/*   Updated: 2024/04/04 15:54:27 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

int	ft_letemcook(t_scene *scene)
{
	int	i;

	i = 0;
	scene->running_time = 1;
	while (i < scene->nb_philos)
	{
		if (pthread_join(scene->philos[i]->p, NULL) != 0)
			return (0);
		i++;
	}
	scene->running_time = 0;
	if (pthread_join(scene->philos[i]->p, NULL))
		return (0);
	return (1);
}

void* philo_life(void* arg)
{
	
}