/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habenydi <habenydi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:43:28 by habenydi          #+#    #+#             */
/*   Updated: 2025/02/18 11:43:53 by habenydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	mover(t_mlx *mlx)
{
	t_cord	p;

	p = findplayer(mlx->map);
	if (mlx->map[p.y][p.x + 1] != '1')
	{
		if (mlx->map[p.y][p.x + 1] == 'C')
			mlx->pec->coin--;
		if (mlx->map[p.y][p.x + 1] == 'E')
			exit(0);
		mlx->map[p.y][p.x] = '0';
		mlx->map[p.y][p.x + 1] = 'P';
		putmap(mlx);
	}
}

void	movel(t_mlx *mlx)
{
	t_cord	p;

	p = findplayer(mlx->map);
	if (mlx->map[p.y][p.x - 1] != '1')
	{
		if (mlx->map[p.y][p.x - 1] == 'C')
			(mlx->pec->coin)--;
		if (mlx->map[p.y][p.x - 1] == 'E')
			exit(0);
		mlx->map[p.y][p.x] = '0';
		mlx->map[p.y][p.x - 1] = 'P';
		putmap(mlx);
	}
}

void	moved(t_mlx *mlx)
{
	t_cord	p;

	p = findplayer(mlx->map);
	if (mlx->map[p.y + 1][p.x] != '1')
	{
		if (mlx->map[p.y + 1][p.x] == 'C')
			(mlx->pec->coin)--;
		if (mlx->map[p.y + 1][p.x] == 'E')
			exit(0);
		mlx->map[p.y][p.x] = '0';
		mlx->map[p.y + 1][p.x] = 'P';
		putmap(mlx);
	}
}

void	moveu(t_mlx *mlx)
{
	t_cord	p;

	p = findplayer(mlx->map);
	if (mlx->map[p.y - 1][p.x] != '1')
	{
		if (mlx->map[p.y - 1][p.x] == 'C')
			(mlx->pec->coin)--;
		if (mlx->map[p.y - 1][p.x] == 'E')
			exit(0);
		mlx->map[p.y][p.x] = '0';
		mlx->map[p.y - 1][p.x] = 'P';
		putmap(mlx);
	}
}

int	move(int key, void *prm)
{
	t_mlx *mlx;

	mlx = (t_mlx *)prm;
	if (key == 100)
		mover(mlx);
	if (key == 119)
		moveu(mlx);
	if (key == 115)
		moved(mlx);
	if (key == 97)
		movel(mlx);
	if (key == 65307)
		exit(0);
	return (0);
}
