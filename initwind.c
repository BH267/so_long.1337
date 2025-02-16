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

void	putimg(t_mlx mlx, int x, int y)
{
	int	w;
	int	h;

	w = 64;
	h = 64;
	mlx.pimg = mlx_xpm_file_to_image(mlx.mlx, "assets/wall.xpm", &w, &h); 
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.pimg, x, y);
}

void	putimges(t_mlx mlx)
{
	int	j;
	int	i;

	i = 0;
	while (i < 700)
	{
		j = 0;
		while (j < 900)
		{
			putimg(mlx, j, i);
			j += 64;
		}
		i += 64;
	}
}

void	dispwind(void)
{
	t_mlx	mlx;

	mlx.mlx = mlx_init();
	if (!mlx.mlx)
		return ;
	mlx.mlx_win = mlx_new_window(mlx.mlx, 900, 700, "awdii");
	if (!mlx.mlx_win)
		return ;
	putimges(mlx);
	mlx_loop(mlx.mlx);
}
