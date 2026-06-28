/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htate <htate@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 17:01:56 by htate             #+#    #+#             */
/*   Updated: 2026/06/28 17:43:29 by htate            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_ceil(int start_y, int x)
{
	t_data		*data;
	t_config	**config;
	int			celling_start;
	int			celling_end;

	celling_start = 0;
	celling_end = start_y;
	data = get_t_data();
	config = get_config();
	while (celling_start < celling_end)
	{
		my_mlx_pixel_put(&data->img, x, celling_start, create_trgb(1,
				(*config)->ceil.color[0], (*config)->ceil.color[1],
				(*config)->ceil.color[2]));
		celling_start++;
	}
}

static void	draw_floor(int end_y, int x)
{
	t_data		*data;
	t_config	**config;
	int			floor_start;
	int			floor_end;

	floor_start = end_y;
	if (floor_start < 0)
		return ;
	floor_end = HEIGHT;
	data = get_t_data();
	config = get_config();
	while (floor_start < floor_end)
	{
		my_mlx_pixel_put(&data->img, x, floor_start, create_trgb(1,
				(*config)->floor.color[0], (*config)->floor.color[1],
				(*config)->floor.color[2]));
		floor_start++;
	}
}

static void	draw_player_ray(t_player *player, double start_x, int i)
{
	t_player_ray	player_ray;
	int				map_x;
	int				map_y;

	map_x = (int)player->pos.x;
	map_y = (int)player->pos.y;
	init_player_ray(&player_ray, map_x, map_y, start_x);
	calc_player_ray(&player_ray, map_x, map_y);
	draw_ceil(player_ray.start_y, i);
	draw_texture(player_ray, i);
	draw_floor(player_ray.end_y, i);
}

void	draw(void)
{
	t_player	*player;
	double		start;
	int			i;

	player = get_player();
	start = player->angle - player->fov / 2;
	i = 0;
	while (i < WIDTH)
	{
		draw_player_ray(player, start, i);
		start += player->fov / WIDTH;
		i++;
	}
}
