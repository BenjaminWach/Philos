/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:10:07 by bwach             #+#    #+#             */
/*   Updated: 2024/04/01 10:34:23 by bwach            ###   ########.fr       */
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