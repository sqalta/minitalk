/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalta <spalta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:17:06 by spalta            #+#    #+#             */
/*   Updated: 2023/01/29 20:32:38 by spalta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int ft_atoi(char *st)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (*(st + i))
	{
		result *= 10;
		result += (*(st + i) - '0');
		i++;
	}
	return (result);
}

int main (int ac, char **av)
{
	int	pid;

	if (ac >= 2)
		pid = ft_atoi(av[1]);
	else
		return (0);
	int		i;
	int		j;
	int		k;
	char	tmp;

	
	i = 0;
	while (av[2][j])
	{
		while (i <= 7)
		{
			tmp = av[2][j];
			tmp >> 7;
			if (tmp & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			av[2][j] << 1;
			i++;
		}
		j++;
	}
}
