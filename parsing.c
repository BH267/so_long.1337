/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habenydi <habenydi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:40:08 by habenydi          #+#    #+#             */
/*   Updated: 2025/02/12 14:33:48 by habenydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	ft_msize(char *map)
{
	int		i;
	int		fd;
	char	*s;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		ft_rputstr("open failed", NULL);
	s = get_next_line(fd);
	i = 0;
	while (s)
	{
		i++;
		free(s);
		s = get_next_line(fd);
	}
	close(fd);
	return (i);
}

void	ft_checkway(char **cmap, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (cmap[i])
	{
		j = 0;
		while (cmap[i][j])
		{
			if (cmap[i][j] == 'C')
			{
				hb_mtrfree(cmap);
				ft_rputstr("invalid map", map);
			}
			j++;
		}
		i++;
	}
}

void	ft_parsing(char *m)
{
	char	**map;
	char	**cmap;
	t_cord	p;

	map = openmap(m);
	ft_isvalid(map);
	ft_checkwall(map, ft_msize(m) - 1);
	ft_checkpce(map);
	cmap = hb_mtrcpy(map);
	p = findplayer(map);
	ft_floodfill(cmap, p.x, p.y);
	ft_checkway(cmap, map);
}
