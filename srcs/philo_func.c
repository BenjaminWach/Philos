/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 22:33:02 by bwach             #+#    #+#             */
/*   Updated: 2024/04/05 19:08:15 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

int	philo_eat(t_scene *scene, t_philo *philo)
{
	if (pthread_mutex_lock(&scene->fork_mutex[philo->fork1]) == 0)
	{
		if (scene->nb_philos < 2)
			philo_lonely(scene, philo);
		if (!life_is_on(scene))
			return ;
		printf("%d %d has taken a fork\n", ft_gettime() - scene->start,
			philo->id);
		if ()
	}
}