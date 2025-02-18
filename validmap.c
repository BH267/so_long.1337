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

void	ft_isvalid(char **map)
{
	size_t	size;
	int		i;

	size = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if (size != ft_strlen(map[i]))
			ft_rputstr("invalid map", map);
		i++;
	}
}

void	ft_checkwall(char **map, int size)
{
	int	i;
	int	len;

	len = (int)ft_strlen(map[0]) - 1;
	if (len > 1920 / 64 || size > 1080 / 64)
		ft_rputstr("invalid map", map);
	i = 0;
	while (map[0][i] != '\n')
	{
		if (map[size][i] != '1' || map[0][i] != '1')
			ft_rputstr("invalid map", map);
		i++;
	}
	i = 1;
	while (i < size - 2)
	{
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			ft_rputstr("invalid map", map);
		i++;
	}
}

void	checkperline(char **map, char *line, t_pec *pec)
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
			ft_rputstr("invalid map", map);
		j++;
	}
}

int	ft_checkpce(char **map)
{
	int		i;
	t_pec	pec;
	t_pec	*pce;

	i = 0;
	pec.exit = 0;
	pec.coin = 0;
	pec.player = 0;
	while (map[i])
		checkperline(map, map[i++], &pec);
	if (pec.exit != 1 || pec.player != 1 || pec.coin < 1)
		ft_rputstr("invalid map", map);
	pce = &pec;
	printf("hak 1: %d coin\n", pce->coin);
	return (pce->coin);
}
