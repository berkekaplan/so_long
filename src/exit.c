/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaplan <@student.42kocaeli.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 21:59:12 by mkaplan           #+#    #+#             */
/*   Updated: 2023/05/31 19:08:23 by mkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	err_msg(char *msg)
{
	ft_printf("%s", msg);
	exit(0);
}

void	free_map(char **map, int map_height)
{
	int	i;

	i = 0;
	while (i < map_height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	destroy_img(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img.character);
	mlx_destroy_image(data->mlx, data->img.wall);
	mlx_destroy_image(data->mlx, data->img.coin);
	mlx_destroy_image(data->mlx, data->img.door);
	mlx_destroy_image(data->mlx, data->img.bg);
	mlx_destroy_window(data->mlx, data->win);
}

int	mouse_hook(int mousecode, t_data *data)
{
	err_msg("Exit Success");
	return (0);
}

void	exit_door(t_data *data)
{
	if (data->coin_collected == data->coin_count)
	{
		err_msg("FINISH");
		free_map(data->map, data->map_height);
		destroy_img(data);
	}
	else
		ft_printf("Sorry, you can't exit.\n");
}
