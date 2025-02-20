/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initwind.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habenydi <habenydi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:18:22 by habenydi          #+#    #+#             */
/*   Updated: 2025/02/13 12:59:00 by habenydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	putimg(char *path, t_mlx *mlx, int x, int y)
{
	int	w;
	int	h;

	h = 64;
	w = 64;
	mlx->pimg = mlx_xpm_file_to_image(mlx->mlx, path, &w, &h);
	if (!mlx->pimg)
		wexit(mlx, "Error", 1);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->pimg, x, y);
	mlx_destroy_image(mlx->mlx, mlx->pimg);
}

void	putimges(t_mlx *mlx, int x, int y)
{
	if (mlx->map[y / 64][x / 64] == '1')
		putimg("./assets/wall.xpm", mlx, x, y);
	else if (mlx->map[y / 64][x / 64] == 'P')
		putimg("./assets/hero1.xpm", mlx, x, y);
	else if (mlx->map[y / 64][x / 64] == 'C')
		putimg("./assets/keys.xpm", mlx, x, y);
	else if (mlx->map[y / 64][x / 64] == 'E' && (mlx->pec->coin))
		putimg("./assets/closed_door.xpm", mlx, x, y);
	else if (mlx->map[y / 64][x / 64] == 'E' && !(mlx->pec->coin))
		putimg("./assets/opened_door.xpm", mlx, x, y);
	else
		putimg("./assets/floor.xpm", mlx, x, y);
}

void	putmap(t_mlx *mlx)
{
	int	j;
	int	i;
	char	*moves;

	i = 0;
	while (i < mlx->size.my)
	{
		j = 0;
		while (j < mlx->size.mx)
		{
			moves = ft_itoa(mlx->count);
			mlx_string_put(mlx->mlx, mlx->mlx_win, 15, 30, 0, "==| moves :");
			mlx_string_put(mlx->mlx, mlx->mlx_win, 85, 30, 0, moves);
			free(moves);
			putimges(mlx, j, i);
			j += 64;
		}
		i += 64;
	}
}

int	closewind(void *mlx)
{
	wexit(mlx, "EXITED", 0);
	return (0);
}

void	dispwind(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		return ;
	mlx->count = 0;
	mlx->mlx_win = mlx_new_window(mlx->mlx, mlx->size.mx,
			mlx->size.my, "awdii");
	if (!mlx->mlx_win)
		return ;
	putmap(mlx);
	mlx_key_hook(mlx->mlx_win, move, mlx);
	mlx_hook(mlx->mlx_win, 17, 0, closewind, mlx);
	mlx_loop(mlx->mlx);
}
