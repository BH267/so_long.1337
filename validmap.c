/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habenydi <habenydi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 09:35:42 by habenydi          #+#    #+#             */
/*   Updated: 2025/02/13 09:36:11 by habenydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_isvalid(char **map, t_mlx *mlx)
{
	size_t	size;
	int		i;

	size = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if (size != ft_strlen(map[i]))
			ft_rputstr("invalid map", mlx, 1);
		i++;
	}
}

void	ft_checkwall(char **map, int size, t_mlx *mlx)
{
	int	i;
	int	len;

	len = (int)ft_strlen(map[0]) - 1;
	i = 0;
	while (map[0][i] != '\n')
	{
		if (map[size][i] != '1' || map[0][i] != '1')
			ft_rputstr("invalid map", mlx, 1);
		i++;
	}
	i = 1;
	while (i < size - 2)
	{
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			ft_rputstr("invalid map", mlx, 1);
		i++;
	}
}

void	checkperline(t_mlx *mlx, char *line, t_pec *pec)
{
	int	j;

	j = 0;
	while (line[j])
	{
		if (line[j] == 'E')
			pec->exit++;
		else if (line[j] == 'C')
			pec->coin++;
		else if (line[j] == 'P')
			pec->player++;
		else if (line[j] != '1' && line[j] != '0' && line[j] != '\n')
			ft_rputstr("invalid map", mlx, 1);
		j++;
	}
}

int	ft_checkpce(t_mlx *mlx)
{
	int		i;
	t_pec	pec;

	i = 0;
	pec.exit = 0;
	pec.coin = 0;
	pec.player = 0;
	pec.enemy = 0;
	while (mlx->map[i])
		checkperline(mlx, mlx->map[i++], &pec);
	if (pec.exit != 1 || pec.player != 1 || pec.coin < 1)
		ft_rputstr("invalid map", mlx, 1);
	return (pec.coin);
}
