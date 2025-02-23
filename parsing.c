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
		ft_rputstr("open failed", NULL, 1);
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

void	ft_checkway(char **cmap, t_mlx *mlx)
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
				ft_rputstr("invalid map", mlx, 1);
			}
			j++;
		}
		i++;
	}
}

t_mlx	ft_parsing(char *m)
{
	t_mlx	mlx;
	char	**cmap;
	t_cord	p;

  mlx.pec = NULL;
	mlx.map = openmap(m);
	mlx.size.mx = (ft_strlen(mlx.map[1]) - 1) * 64;
	mlx.size.my = ft_msize(m) * 64;
	if (mlx.size.my == 64)
		ft_rputstr("invalid map", &mlx, 1);
	ft_isvalid(mlx.map, &mlx);
	ft_checkwall(mlx.map, ft_msize(m) - 1, &mlx);
	mlx.pec = malloc(sizeof(t_pec));
	mlx.pec->coin = ft_checkpce(&mlx);
	cmap = hb_mtrcpy(mlx.map);
	p = findplayer(mlx.map, 'P');
	ft_floodfill(cmap, p.x, p.y);
	ft_checkway(cmap, &mlx);
  enemygen(&mlx);
	hb_mtrfree(cmap);
	return (mlx);
}
