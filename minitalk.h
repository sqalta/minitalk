/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalta <spalta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:58:20 by spalta            #+#    #+#             */
/*   Updated: 2023/02/01 23:14:01 by spalta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <stdarg.h>

void	catch_signal(int signum, siginfo_t *siginfo, void *unused);
void	ft_send_signal(char *str, int pid);
int		ft_atoi(char *st);
void	ft_handle(int sig, siginfo_t *siginfo, void *unused);
int		convert_c(int sig, int i);
int		ft_printf(const char *s, ...);
void	ft_check(va_list *list, char a, int *result);
void	ft_putnbr(int n, int *result);
void	ft_putstr(char *s, int *result);
void	ft_putchar(char c, int *result);

#endif