/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaplan <@student.42kocaeli.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 21:59:36 by mkaplan           #+#    #+#             */
/*   Updated: 2023/06/01 10:09:26 by mkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ber_control(char *map_name, t_data *data)
{
	int	arg_len;

	arg_len = ft_strlen(map_name);
	if (map_name[arg_len - 1] != 'r' || map_name[arg_len - 2] != 'e'
		|| map_name[arg_len - 3] != 'b' || map_name[arg_len - 4] != '.')
		err_msg("Error\nMap file is not .ber");
}

void	tmp_control(char *map_name, t_data *data)
{
	int		fd;

	fd = open(ft_strjoin("maps/", map_name), O_RDONLY);
	if (fd == -1)
		err_msg("Error\nMap file is not found");
	if (!map_name)
		free(map_name);
}

void	map_control(char **argv, t_data *data)
{
	char	*map_name;
	char	*map_names;

	if (argv[1] == NULL)
		err_msg("Error\nNo map file");
	map_name = argv[1];
	map_names = ft_strjoin("maps/", map_name);
	data->map_tmp = map_names;
	free(map_names);
	ber_control(argv[1], data);
	tmp_control(argv[1], data);
}
