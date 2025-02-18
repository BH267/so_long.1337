/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habenydi <habenydi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:54:52 by habenydi          #+#    #+#             */
/*   Updated: 2025/02/16 10:39:02 by habenydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <mlx.h>
# include "gnl/get_next_line.h"

typedef struct s_cordinate
{
	int	x;
	int	y;
	int	mx;
	int	my;
}	t_cord;

typedef struct s_pec
{
	int	player;
	int	exit;
	int	coin;
	int	enemy;
}	t_pec;

typedef struct s_mlx
{
	t_cord	size;
	char	**map;
	void	*mlx;
	void	*mlx_win;
	void	*pimg;
	t_pec	*pec;
}	t_mlx;

// aditional functions
void	hb_mtrfree(char **mtr);
char	**hb_mtrcpy(char **mtr);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
int		ft_free(char **s, ssize_t i);
void	ft_rputstr(char *s, char **map);

// parsing functions
char	**openmap(char *m);
int		ft_msize(char *map);
t_mlx	ft_parsing(char *m);
void	ft_isvalid(char **map);
t_cord	findplayer(char **map);
int	ft_checkpce(char **map);
void	ft_floodfill(char **map, int x, int y);
void	ft_checkwall(char **map, int size);

// game function
void	putmap(t_mlx *mlx);
void	dispwind(t_mlx *mlx);
int	move(int key, void *prm);
void	putimges(t_mlx *mlx, int x, int y);
t_cord	findplayer(char **map);

#endif
