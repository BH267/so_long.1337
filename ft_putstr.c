#include "solong.h"

void	ft_putstr(char *str, int nl)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, str + i, 1);
		i++;
	}
	if (nl)
		write(1, "\n", 1);
}
