/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   groundcontrol_to.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 11:40:32 by bwach             #+#    #+#             */
/*   Updated: 2024/04/04 15:54:23 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

int	check_death_philo(int time, t_scene *scene, t_philo *philo)
{
	if (time == philo->time_ofdeath)
	{
		printf("%d philo number %d has died\n",time ,philo->id);
		return (0);
	}
	else
	{
		return (1);
	}
}

//check if le philo est mort ou non
void	*ft_control(void *arg)
{
	t_scene	*scene;
	int		current_time;
	int		id;

	scene = (t_scene *)arg;
	current_time = 0;
	while (!scene->running_time)
	{
	}
	while (scene->running_time)
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
