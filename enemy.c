/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habenydi <habenydi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:25:43 by habenydi          #+#    #+#             */
/*   Updated: 2025/02/23 17:25:55 by habenydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "solong.h"

int numgen(int max)
{
  srand(time(NULL));
  return (1 + rand() % max);
}

void  enemygen(t_mlx *mlx)
{
  int y;
  int x;

  while (1)
  {
    y = numgen((mlx->size.my / 64) - 1);
    x = numgen((mlx->size.mx / 64) - 1);
    if (mlx->map[y][x] == '0')
    {
      mlx->map[y][x] = 'X';
      break;
    }
  } 
}

void	fillenemy(t_mlx *mlx)
{
	int	i;

	mlx->enemy = (char **)malloc(sizeof(char *) * 8);
	if (!mlx->enemy)
		wexit(mlx, "malloc failed", 1);
	mlx->enemy[0] = ft_strdup("textures/enemy/fly1.xpm");
	i = 1;
	while (i < 4)
	{
		mlx->enemy[i] = ft_strdup(mlx->enemy[0]);
		mlx->enemy[i][ft_strlen(mlx->enemy[0]) - 5] += i;
		i++;
	}
	mlx->enemy[i] = NULL;
}

void  emove(t_mlx *mlx, char d, t_cord e)
{
  while (mlx->map[e.y][e.x + 1] == '1' 
    || mlx->map[e.y][e.x + 1] == 'C')
    {
    (void)d;
  }
}

void  moveye(t_mlx *mlx)
{
  t_cord  p;
  t_cord  x;

  p = findplayer(mlx->map, 'P');
  x = findplayer(mlx->map, 'X');
  if (x.x == p.x)
    emove(mlx, 'y', x);
  else if (x.y == p.y)
    emove(mlx, 'x', x);
}

/*
int	findenemy(t_mlx *mlx)
{
	int			i;
	int			j;
	static int	frame;

	j = 0;
	i = 0;
	while (mlx->map[i])
	{
		j = 0;
		while (mlx->map[i][j])
		{
			if (mlx->map[i][j] == 'X')
				putimg(mlx->enemy[frame], mlx, j * 64, i * 64);
			j++;
		}
		i++;
	}
	if (frame < 3)
		frame++;
	else
		frame = 0;
	return (0);
}

int	doara2(t_mlx *mlx)
{
	static int	cnt;

	if (cnt % 4999 == 0)
		findenemy(mlx);
	cnt++;
	return (0);
}*/
