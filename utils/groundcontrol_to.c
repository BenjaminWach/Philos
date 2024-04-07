/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   groundcontrol_to.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 11:40:32 by bwach             #+#    #+#             */
/*   Updated: 2024/04/07 10:18:42 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

//security for the running_time
int	simulation_is_on(t_scene *scene)
{
	pthread_mutex_lock(&scene->scene_mutex);
	if (scene->is_running)
	{
		pthread_mutex_unlock(&scene->scene_mutex);
		return (1);
	}
	pthread_mutex_unlock(&scene->scene_mutex);
	return (0);
}

int	check_death_philo(int time, t_scene *scene, t_philo *philo)
{
	int	time_elasped;

	time_elasped = time - scene->start;
	if (philo->time_ofdeath < (time_elasped))
	{
		pthread_mutex_lock(&scene->scene_mutex);
		scene->is_running = 0;
		philo->time_ofdeath = ft_gettime();
		printf("%d %d is dead\n", time_elasped, philo->id);
		pthread_mutex_unlock(&scene->scene_mutex);
		return (0);
	}
	return (1);
}

//check if le philo est mort ou non
void	*ft_control(void *arg)
{
	t_scene	*scene;
	int		current_time;
	int		id;

	scene = (t_scene *)arg;
	current_time = 0;
	while (!scene->is_running)
	{
	}
	while (scene->is_running)
	{
		id = 0;
		current_time = ft_gettime();
		while (scene->philos[id])
		{
			if (check_death_philo(current_time, scene, scene->philos[id]))
				break ;
		}
	}
	return (NULL);
}
