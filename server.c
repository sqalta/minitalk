/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalta <spalta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:17:02 by spalta            #+#    #+#             */
/*   Updated: 2023/02/01 22:45:27 by spalta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	convert_c(int sig, int i)
{
	int	book;

	book = 0;
	if (sig == 30)
	{
		book = 1;
		while (i)
		{
			book *= 2;
			i--;
		}
	}
	return (book);
}

void	ft_handle(int sig, siginfo_t *siginfo, void *unused)
{
	static int	count;
	static int	ret;
	int			book;
	int			i;

	(void)unused;
	i = 7 - count;
	book = convert_c(sig, i);
	ret += book;
	count++;
	if (count == 8)
	{
		write(1, &ret, 1);
		ret = 0;
		count = 0;
		if (kill(siginfo->si_pid, SIGUSR2) == -1)
			ft_printf("%s\n", "The signal could not be sent");
	}
}

int	main(void)
{
	struct sigaction	sinyal;
	int					pid;

	pid = getpid();
	ft_printf("%s%d\n", "Pid->", pid);
	sinyal.sa_flags = SA_SIGINFO;
	sinyal.sa_sigaction = ft_handle;
	if (sigaction(SIGUSR1, &sinyal, 0) == -1)
		ft_printf("%s\n", "Wrong Signal");
	if (sigaction(SIGUSR2, &sinyal, 0) == -1)
		ft_printf("%s\n", "Wrong Signal");
	while (1)
		pause();
	return (0);
}
