/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htate <htate@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 17:01:56 by htate             #+#    #+#             */
/*   Updated: 2026/06/28 17:02:12 by htate            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_exit(t_config *config, t_map *config_file)
{
	all_free(config, config_file);
	exit(1);
}

int	open_cubfile(int argc, char *filename)
{
	int	len;
	int	fd;

	if (argc != 2)
	{
		print_error("please input one file that have a .cub extension");
		exit(1);
	}
	len = ft_strlen(filename);
	if (len < 4 || ft_strncmp(filename + len - 4, ".cub", 4) != 0)
	{
		print_error("The file must have a .cub extension");
		exit(1);
	}
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		print_error("problem loading the file.");
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
