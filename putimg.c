/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putimg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habenydi <habenydi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:26:05 by habenydi          #+#    #+#             */
/*   Updated: 2025/02/15 16:33:56 by habenydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	putimg(t_mlx mlx)
{
	int	w;
	int	h;

	w = 64;
	h = 64;
	mlx.pimg = mlx_xpm_file_to_image(mlx.mlx, "wall.xpm", &w, &h); 
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.pimg, 0, 0);
}
