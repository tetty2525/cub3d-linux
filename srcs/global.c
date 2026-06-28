/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htate <htate@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 17:01:56 by htate             #+#    #+#             */
/*   Updated: 2026/06/28 17:02:12 by htate            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_data	*get_t_data(void)
{
	static t_data	data;

	return (&data);
}

t_player	*get_player(void)
{
	static t_player	player;

	return (&player);
}

t_texture_img	*get_texture_img(void)
{
	static t_texture_img	texture_img[4];

	return (texture_img);
}

t_config	**get_config(void)
{
	static t_config	*config;

	return (&config);
}
