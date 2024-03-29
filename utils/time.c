/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:10:07 by bwach             #+#    #+#             */
/*   Updated: 2024/03/29 16:27:05 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

int	ft_gettime(void)
{
	struct timespec	time;
	int				mill_sec;

	clock_gettime(CLOCK_MONOTONIC, &time);
	mill_sec = time.tv_sec * 1000L + time.tv_nsec / 1e6;
	return (mill_sec);
}
