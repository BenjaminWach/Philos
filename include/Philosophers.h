/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:02:15 by bwach             #+#    #+#             */
/*   Updated: 2024/04/03 15:31:56 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <memory.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_philo
{
	pthread_t		p;
	int				id;
	int				nb_meal;
	int				time_lastmeal;
	int				time_ofdeath;
	int				fork1;
	int				fork2;
	struct s_scene	*scene;
}	t_philo;

typedef struct s_scene
{
	int				running_time;
	int				nb_philos;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				nb_meals;
	int				start;
	t_philo			**philos;
	pthread_t		monitor;
	pthread_mutex_t	scene_mutex;
	pthread_mutex_t	*fork_mutex;
}	t_scene;

//main
int	main(int ac, char **av);

//time
int	ft_gettime(void);

//utils
int	ft_atoi(const char *str);
int	is_negative(int ac, char **av);
int	mutex_init(t_scene *scene);
int	philo_init(t_scene *scene);
int	ft_control(void);

#endif