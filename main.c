/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habenydi <habenydi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:26:01 by habenydi          #+#    #+#             */
/*   Updated: 2025/02/08 15:27:51 by habenydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2 && *s1 && *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	validpath(char *ber)
{
	if (!ft_strcmp(ber, ".ber"))
		ft_rputstr("invalid path", NULL, 1);
	while (*ber)
		ber++;
	ber -= 4;
	if (*(ber - 1) == '/')
		ft_rputstr("invalid path", NULL, 1);
	if (ft_strcmp(ber, ".ber"))
		ft_rputstr("invalid path", NULL, 1);
}

int	main(int ac, char **av)
{
	t_mlx	mlx;

	if (ac != 2)
		return (1);
	validpath(av[1]);
	mlx = ft_parsing(av[1]);
  mlx.path = av[0];
	dispwind(&mlx);
}
