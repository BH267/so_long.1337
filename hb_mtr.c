/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hb_mtrcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habenydi <habenydi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:14:13 by habenydi          #+#    #+#             */
/*   Updated: 2025/02/12 14:34:04 by habenydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

size_t	hb_mtrlen(char **mtr)
{
	size_t	i;

	i = 0;
	while (mtr[i])
		i++;
	return (i);
}

char	**hb_mtrcpy(char **mtr)
{
	char	**m;
	size_t	i;

	m = (char **)malloc(hb_mtrlen(mtr) * (sizeof(char *) + 2));
	if (!m)
		return (NULL);
	i = 0;
	while (mtr[i])
	{
		m[i] = ft_strdup(mtr[i]);
		i++;
	}
	m[i] = NULL;
	return (m);
}

void	hb_mtrfree(char **mtr)
{
	int	i;

	i = 0;
	while (mtr && mtr[i])
		free(mtr[i++]);
	free(mtr);
}
