/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalta <spalta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:17:02 by spalta            #+#    #+#             */
/*   Updated: 2023/01/29 20:57:52 by spalta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void	ft_handle(int sig)
{
	static int	a;
	static int	count;

	a <<= 1;
	if (sig == SIGUSR1)
		a |= 1;
	count++;
	if (count == 8)
	{
		write(1, &a, 1);
		count = 0;
	}
}

int	main(void)
{
	pid_t	a;

	a = getpid();
	printf("%d\n", a);
	signal(SIGUSR1, ft_handle);
	signal(SIGUSR2, ft_handle);
	while (1)
		continue ;
}