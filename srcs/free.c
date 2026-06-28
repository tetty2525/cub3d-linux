/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htate <htate@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 17:01:56 by htate             #+#    #+#             */
/*   Updated: 2026/06/28 17:02:12 by htate            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_texture_image(void)
{
	t_data			*data;
	t_texture_img	*texture_img;

	texture_img = get_texture_img();
	data = get_t_data();
	if (texture_img[NORTH].img)
		mlx_destroy_image(data->mlx, texture_img[NORTH].img);
	if (texture_img[SOUTH].img)
		mlx_destroy_image(data->mlx, texture_img[SOUTH].img);
	if (texture_img[EAST].img)
		mlx_destroy_image(data->mlx, texture_img[EAST].img);
	if (texture_img[WEST].img)
		mlx_destroy_image(data->mlx, texture_img[WEST].img);
	if (data->img.img)
		mlx_destroy_image(data->mlx, data->img.img);
}

/* Linux: mlx_init() が malloc した構造体なので free で正しく解放できる */
void	free_t_data(void)
{
	t_data	*data;

	data = get_t_data();
	if (data->mlx)
		free(data->mlx);
}
