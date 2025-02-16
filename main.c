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
		ft_rputstr("invalid path", NULL);
	while (*ber)
		ber++;
	ber -= 4;
	if (*(ber - 1) == '/')
		ft_rputstr("invalid path", NULL);
	if (ft_strcmp(ber, ".ber"))
		ft_rputstr("invalid path", NULL);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	validpath(av[1]);
	ft_parsing(av[1]);
	dispwind();
}
