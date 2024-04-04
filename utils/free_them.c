/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_them.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:25:47 by bwach             #+#    #+#             */
/*   Updated: 2024/04/04 11:34:47 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

void	free_struct(t_scene *scene)
{
	int	i;

	i = 0;
	if (!scene->philos)
	{
		while (i < scene->nb_philos)
		{
			free(scene->philos[i]);
			i++;
		}
		free(scene);
	}
}
