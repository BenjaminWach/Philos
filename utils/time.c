/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:10:07 by bwach             #+#    #+#             */
/*   Updated: 2024/04/06 17:50:48 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

int	ft_gettime(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1e3) + (time.tv_usec / 1e6));
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
