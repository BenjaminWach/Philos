/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:10:07 by bwach             #+#    #+#             */
/*   Updated: 2024/04/05 19:06:12 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

int	ft_gettime(void)
{
	struct timespec	time;
	int				mill_sec;

	clock_gettime(&time, NULL);
	mill_sec = time.tv_sec * 1000 + time.tv_nsec / 1000;
	return (mill_sec);
}

//philo impair is sleeping at the start
void	timeto_sleep(int usec)
{
	struct timeval	start;
	struct timeval	current;
	int				elapsed;
	int				remaining;

	gettimeofday(&start, NULL);
	elapsed = 0;
	while (elapsed < usec)
	{
		remaining = usec - elapsed;
		if (remaining > 1e3)
			usleep(remaining / 2);
		gettimeofday(&current, NULL);
		elapsed = (current.tv_sec - start.tv_sec) * 1e6 \
			+ (current.tv_usec - start.tv_usec);
	}
}
