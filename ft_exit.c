/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habenydi <habenydi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:28:22 by habenydi          #+#    #+#             */
/*   Updated: 2025/02/18 16:33:52 by habenydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_rputstr(char *s, t_mlx *mlx, int f)
{
	int	i;

	i = 0;
	if (f)
		write(2, "Error\n", 6);
	while (s[i])
	{
		write(2, s + i, 1);
		i++;
	}
	write(2, "\n", 1);
  if (mlx)
  {
    free(mlx->pec);
	  hb_mtrfree(mlx->map);
  }
	exit(f);
}

void	wexit(t_mlx *mlx, char *str, int f)
{
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	mlx_destroy_display(mlx->mlx);
	hb_mtrfree(mlx->coin);
	free(mlx->mlx);
  free(mlx->path);
	ft_rputstr(str, mlx, f);
}
