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


void  ft_path(t_mlx *mlx)
{
  int i;
  int len;

  i = 0;
  while (mlx->path[i])
  {
    if (mlx->path[i] == '/')
      len = i + 1;
    i++;
  }
  mlx->path = ft_gsubstr(mlx->path, len);
}

void	putimg(char *path, t_mlx *mlx, int x, int y)
{
	int	w;
	int	h;

	h = 64;
	w = 64;
  path = ft_strjoin(mlx->path, path);
	mlx->pimg = mlx_xpm_file_to_image(mlx->mlx, path, &w, &h);
	if (!mlx->pimg)
		wexit(mlx, "xpm_file_to_image failed", 1);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->pimg, x, y);
  free(path);
	mlx_destroy_image(mlx->mlx, mlx->pimg);
}

void	putimges(t_mlx *mlx, int x, int y)
{
	if (mlx->map[y / 64][x / 64] == '1')
		putimg("textures/wall.xpm", mlx, x, y);
	else if (mlx->map[y / 64][x / 64] == 'P')
		putimg("textures/hero1.xpm", mlx, x, y);
	else if (mlx->map[y / 64][x / 64] == 'C')
		mlx_loop_hook(mlx->mlx, doara, mlx);
	else if (mlx->map[y / 64][x / 64] == 'E' && (mlx->pec->coin))
		putimg("textures/closed_door.xpm", mlx, x, y);
	else if (mlx->map[y / 64][x / 64] == 'E' && !(mlx->pec->coin))
		putimg("textures/opened_door.xpm", mlx, x, y);
	else
		putimg("textures/floor.xpm", mlx, x, y);
 // else if (mlx->map[y / 64][x / 64] == 'X')
	//	mlx_loop_hook(mlx->mlx, doara2, mlx);
}

void	putmap(t_mlx *mlx)
{
	int		j;
	int		i;
	char	*moves;

	moves = ft_itoa(mlx->count);
	ft_putstr("==| moves :", 0);
	ft_putstr(moves, 1);
	i = 0;
	while (i < mlx->size.my)
	{
		j = 0;
		while (j < mlx->size.mx)
		{
			mlx_string_put(mlx->mlx, mlx->mlx_win, 15, 30, 0, "==| moves :");
			mlx_string_put(mlx->mlx, mlx->mlx_win, 85, 30, 0, moves);
			putimges(mlx, j, i);
			j += 64;
		}
		i += 64;
	}
	free(moves);
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
  ft_path(mlx);
	fillcoin(mlx);
	fillenemy(mlx);
	putmap(mlx);
	mlx_key_hook(mlx->mlx_win, move, mlx);
	mlx_hook(mlx->mlx_win, 17, 0, closewind, mlx);
	mlx_loop(mlx->mlx);
}
