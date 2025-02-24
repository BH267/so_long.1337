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

	mlx->coin = (char **)malloc(sizeof(char *) * 8);
	if (!mlx->coin)
		wexit(mlx, "malloc failed", 1);
	/*mlx->coin[0] = ft_strjoin(mlx->path, "textures/coin/coin1.xpm");*/
	mlx->coin[0] = ft_strdup("textures/coin/coin1.xpm");
	i = 1;
	while (i < 7)
	{
		mlx->coin[i] = ft_strdup(mlx->coin[0]);
		mlx->coin[i][ft_strlen(mlx->coin[0]) - 5] += i;
		i++;
	}
	mlx->coin[i] = NULL;
}

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
	if (frame < 6)
		frame++;
	else
		frame = 0;
	return (0);
}
