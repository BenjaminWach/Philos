/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:32:14 by bwach             #+#    #+#             */
/*   Updated: 2024/04/01 10:48:31 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

int	init_struct_scene(t_scene *scene, int ac, char **av)
{
	scene->running_time = 0;
	scene->nb_philos = ft_atoi(av[1]);
	scene->die_time = ft_atoi(av[2]);
	scene->eat_time = ft_atoi(av[3]);
	scene->sleep_time = ft_atoi(av[4]);
	scene->start = ft_gettime();
	if (ac == 6)
		scene->nb_meals = ft_atoi(av[5]);
	if (ac == 5)
		scene->nb_meals = -1;
	scene->philos = NULL;
	pthread_mutex_init(&scene->scene_mutex, NULL);
	if (!mutex_init(scene))
		return (0);
	if (!philo_init(scene))
		return (0);
	return (1);
}

static int	check_valid_args(int ac, char **av)
{
	if ((ac > 6 || ac < 5) || !is_negative(ac, av))
	{
		printf("Enter the right format for the args"
			"or Use positive numbers only!\n");
		return (-1);
	}
	if (ft_atoi(av[1]) == 0)
		return (-1);
	return (0);
}

int	main(int ac, char **av)
{
	t_scene	scene;

	if (!check_valid_args(ac, av))
	{
		return (-1);
	}
	if (init_struct_scene(&scene, ac, av))
		philo_life(&scene);
	free_struct(scene);
}
