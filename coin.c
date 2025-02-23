/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coin.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habenydi <habenydi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 10:19:04 by habenydi          #+#    #+#             */
/*   Updated: 2025/02/23 10:19:18 by habenydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	fillcoin(t_mlx *mlx)
{
	int	i;

	mlx->coin = (char **)malloc(sizeof(char *) * 8);
	if (!mlx->coin)
		wexit(mlx, "malloc failed", 1);
	mlx->coin[0] = ft_strdup("./textures/coin/coin1.xpm");
	i = 1;
	while (i < 7)
	{
		mlx->coin[i] = ft_strdup(mlx->coin[0]);
		mlx->coin[i][20] += i;
		i++;
	}
	mlx->coin[i] = NULL;
}

int	findcoins(t_mlx *mlx)
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
			if (mlx->map[i][j] == 'C')
				putimg(mlx->coin[frame], mlx, j * 64, i * 64);
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

int	doara(t_mlx *mlx)
{
	static int	cnt;

	if (cnt % 4999 == 0)
		findcoins(mlx);
	cnt++;
	return (0);
}
