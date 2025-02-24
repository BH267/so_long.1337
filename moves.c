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

	p = findplayer(mlx->map, 'P');
	if (mlx->map[p.y][p.x + 1] != '1')
	{
		mlx->count++;
		if (mlx->map[p.y][p.x + 1] == 'C')
			mlx->pec->coin--;
		if (mlx->map[p.y][p.x + 1] == 'E' && !mlx->pec->coin)
			wexit(mlx, "YOU WIN", 0);
		else if (mlx->map[p.y][p.x + 1] == 'E' && mlx->pec->coin)
			return ;
    if (mlx->map[p.y][p.x + 1] == 'X')
      wexit(mlx, "YOU LOSE", 0);
		mlx->map[p.y][p.x] = '0';
		mlx->map[p.y][p.x + 1] = 'P';
		putmap(mlx);
	}
}

void	movel(t_mlx *mlx)
{
	t_cord	p;

	p = findplayer(mlx->map, 'P');
	if (mlx->map[p.y][p.x - 1] != '1')
	{
		mlx->count++;
		if (mlx->map[p.y][p.x - 1] == 'C')
			(mlx->pec->coin)--;
		if (mlx->map[p.y][p.x - 1] == 'E' && !mlx->pec->coin)
			wexit(mlx, "YOU WIN", 0);
		else if (mlx->map[p.y][p.x - 1] == 'E' && mlx->pec->coin)
			return ;
    if (mlx->map[p.y][p.x - 1] == 'X')
      wexit(mlx, "YOU LOSE", 0);
		mlx->map[p.y][p.x] = '0';
		mlx->map[p.y][p.x - 1] = 'P';
		putmap(mlx);
	}
}

void	moved(t_mlx *mlx)
{
	t_cord	p;

	p = findplayer(mlx->map, 'P');
	if (mlx->map[p.y + 1][p.x] != '1')
	{
		mlx->count++;
		if (mlx->map[p.y + 1][p.x] == 'C')
			(mlx->pec->coin)--;
		if (mlx->map[p.y + 1][p.x] == 'E' && !mlx->pec->coin)
			wexit(mlx, "YOU WIN", 0);
		else if (mlx->map[p.y + 1][p.x] == 'E' && mlx->pec->coin)
			return ;
    if (mlx->map[p.y + 1][p.x] == 'X')
      wexit(mlx, "YOU LOSE", 0);
		mlx->map[p.y][p.x] = '0';
		mlx->map[p.y + 1][p.x] = 'P';
		putmap(mlx);
	}
}

void	moveu(t_mlx *mlx)
{
	t_cord	p;

	p = findplayer(mlx->map, 'P');
	if (mlx->map[p.y - 1][p.x] != '1')
	{
		mlx->count++;
		if (mlx->map[p.y - 1][p.x] == 'C')
			(mlx->pec->coin)--;
		if (mlx->map[p.y - 1][p.x] == 'E' && !mlx->pec->coin)
			wexit(mlx, "YOU WIN", 0);
		else if (mlx->map[p.y - 1][p.x] == 'E' && mlx->pec->coin)
			return ;
    if (mlx->map[p.y - 1][p.x] == 'X')
      wexit(mlx, "YOU LOSE", 0);
		mlx->map[p.y][p.x] = '0';
		mlx->map[p.y - 1][p.x] = 'P';
		putmap(mlx);
	}
}

int	move(int key, void *prm)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)prm;
	if (key == 100)
		mover(mlx);
	if (key == 119)
		moveu(mlx);
	if (key == 115)
		moved(mlx);
	if (key == 97)
		movel(mlx);
	if (key == 65307 || key == 17)
		wexit(mlx, "EXITED", 0);
	return (0);
}
