/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalta <spalta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:17:06 by spalta            #+#    #+#             */
/*   Updated: 2023/02/01 23:13:51 by spalta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(char *st)
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

void	ft_send_signal(char *str, int pid)
{
	int	i;
	int	j;

	j = 0;
	while (str[j])
	{
		i = 7;
		while (i >= 0)
		{
			if ((str[j] >> i) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			i--;
			usleep(100);
		}
		j++;
	}
}

void	catch_signal(int signum, siginfo_t *siginfo, void *unused)
{
	(void)signum;
	(void)siginfo;
	(void)unused;
	if (signum == SIGUSR2)
		ft_printf("%s\n", "Message sent successfully!");
}

int	main(int ac, char **av)
{
	struct sigaction	signal;
	int					p_id;

	signal.sa_flags = SA_SIGINFO;
	signal.sa_sigaction = catch_signal;
	if (sigaction(SIGUSR1, &signal, 0) == -1)
		ft_printf("%s\n", "Wrong Signal");
	if (sigaction(SIGUSR2, &signal, 0) == -1)
		ft_printf("%s\n", "Wrong Signal");
	if (ac == 3)
	{
		p_id = ft_atoi(av[1]);
		ft_send_signal(av[2], p_id);
	}
	else
		ft_printf("%s", "Try Again");
	return (0);
}
