/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habenydi <habenydi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 09:30:38 by habenydi          #+#    #+#             */
/*   Updated: 2025/02/13 09:31:10 by habenydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_rputstr(char *s, char **map)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(2, s + i, 1);
		i++;
	}
	write(2, "\n", 1);
	//hb_mtrfree(map);
	i = 0;
	while (map != NULL && map[i])
	{
		printf("===| %s", map[i]);
		free(map[i]);
		i++;
	}
	free(map);
	exit(1);
}
