/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htate <htate@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 17:01:56 by htate             #+#    #+#             */
/*   Updated: 2026/06/28 20:08:54 by htate            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_exit(t_config *config, t_map *config_file)
{
	all_free(config, config_file);
	exit(1);
}

static int	is_valid_cub_filename(char *filename)
{
	char	*base_name;
	int		len;

	if (!filename || !*filename)
		return (0);
	base_name = ft_strrchr(filename, '/');
	if (base_name)
		base_name++;
	else
		base_name = filename;
	len = ft_strlen(base_name);
	if (len <= 4)
		return (0);
	if (ft_strncmp(base_name + len - 4, ".cub", 4) != 0)
		return (0);
	return (1);
}

int	open_cubfile(int argc, char *filename)
{
	int	fd;

	if (argc != 2)
	{
		print_error("please input one file that have a .cub extension");
		exit(1);
	}
	if (!is_valid_cub_filename(filename))
	{
		print_error("invalid scene filename");
		exit(1);
	}
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		print_error("cannot open scene file");
		exit(1);
	}
	return (fd);
}

int	main(int argc, char **argv)
{
	int	fd;

	fd = open_cubfile(argc, argv[1]);
	*get_config() = parser(fd);
	init_t_data();
	return (0);
}
