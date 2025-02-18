/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validway.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habenydi <habenydi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:54:34 by habenydi          #+#    #+#             */
/*   Updated: 2025/02/13 11:28:34 by habenydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

t_cord	findplayer(char **map)
{
	int		i;
	int		j;
	t_cord	player;

	player.x = 0;
	player.y = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				player.y = i;
				player.x = j;
				return (player);
			}
			j++;
		}
		i++;
	}
	return (player);
}

void	ft_floodfill(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'E' || map[y][x] == '@')
		return ;
	map[y][x] = '@';
	ft_floodfill(map, x + 1, y);
	ft_floodfill(map, x - 1, y);
	ft_floodfill(map, x, y + 1);
	ft_floodfill(map, x, y - 1);
}

char	**openmap(char *m)
{
	char	*s;
	char	**map;
	int		fd;
	int		i;

	fd = open(m, O_RDONLY);
	if (fd == -1)
		ft_rputstr("open failed", NULL, 1);
	i = 0;
	map = (char **)malloc(sizeof(char *) * (ft_msize(m) + 1));
	if (!map)
		ft_rputstr("malloc failed", NULL, 1);
	s = get_next_line(fd);
	while (s)
	{
		map[i] = s;
		s = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	return (map);
}
