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
# include <time.h>
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
	int		count;
	char	**coin;
  char  **enemy;
  char  *path;
}	t_mlx;

// aditional functions
char	*ft_itoa(int n);
void	hb_mtrfree(char **mtr);
char	**hb_mtrcpy(char **mtr);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
void	ft_putstr(char *str, int nl);
void	ft_bzero(void *ptr, int len);
int		ft_free(char **s, ssize_t i);

// parsing functions
char	**openmap(char *m);
t_mlx	ft_parsing(char *m);
void	ft_isvalid(char **map, t_mlx *mlx);
t_cord	findplayer(char **map, char c);
int		ft_msize(char *map);
int		ft_checkpce(t_mlx *mlx);
void	ft_checkwall(char **map, int size, t_mlx *mlx);
void	ft_floodfill(char **map, int x, int y);

// game function
int		doara(t_mlx *mlx);
int		doara2(t_mlx *mlx);
void	coins(t_mlx *mlx);
void	putmap(t_mlx *mlx);
void	dispwind(t_mlx *mlx);
void	fillcoin(t_mlx *mlx);
void	fillenemy(t_mlx *mlx);
int		findcoins(t_mlx *mlx);
//t_cord	findplayer(char **map, char c);
int		putcoins(t_mlx *mlx);
int		move(int key, void *prm);
void	putimges(t_mlx *mlx, int x, int y);
void	putimg(char *path, t_mlx *mlx, int x, int y);
int		putcoin(t_mlx *mlx);

// enemy function
void enemygen(t_mlx *mlx);

// exit function
void	wexit(t_mlx *mlx, char *s, int f);
void	ft_rputstr(char *s, t_mlx *mlx, int f);

#endif
