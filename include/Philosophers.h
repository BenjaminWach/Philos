/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:02:15 by bwach             #+#    #+#             */
/*   Updated: 2024/04/05 19:05:55 by bwach            ###   ########.fr       */
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
int		main(int ac, char **av);
int		ft_letemcook(t_scene *scene);
void	*philo_life(void *arg);

//philos
void	philo_lonely(t_scene *scene, t_philo *philo);
int		philo_eat(t_scene *scene, t_philo *philo);
int		philo_sleep(t_scene *scene, t_philo *philo);
int		philo_think(t_scene *scene, t_philo *philo);

//time
int		ft_gettime(void);
void	timeto_sleep(int usec);

//utils
int		ft_atoi(const char *str);
int		is_negative(int ac, char **av);
int		mutex_init(t_scene *scene);
int		philo_init(t_scene *scene);
void	forks_init(t_philo *philo, int i, int nb_philos);

//threads
int		ft_control(void);
int		life_is_on(t_scene *scene);

//cleaning
void	free_struct(t_scene *scene);

#endif