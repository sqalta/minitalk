/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalta <spalta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:57:28 by spalta            #+#    #+#             */
/*   Updated: 2023/02/01 17:43:14 by spalta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c, int *result)
{
	write(1, &c, 1);
	*result += 1;
}

void	ft_putstr(char *s, int *result)
{
	size_t	i;

	i = 0;
	if (!s)
	{
		ft_putstr("(null)", result);
		result += 6;
		return ;
	}
	while (s[i])
	{
		ft_putchar(s[i], result);
		i++;
	}
}

void	ft_putnbr(int n, int *result)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648", result));
	if (n < 0)
	{
		ft_putchar('-', result);
		ft_putnbr(-n, result);
	}
	else if (n >= 10)
	{
		ft_putnbr(n / 10, result);
		ft_putchar(n % 10 + '0', result);
	}
	else
		ft_putchar(n + '0', result);
}

void	ft_check(va_list *list, char a, int *result)
{
	if (a == 'c')
		ft_putchar(va_arg(*list, int), result);
	else if (a == '%')
		ft_putchar('%', result);
	else if (a == 's')
		ft_putstr(va_arg(*list, char *), result);
	else if (a == 'd' || a == 'i')
		ft_putnbr(va_arg(*list, int), result);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		result;
	va_list	list;

	i = 0;
	result = 0;
	va_start(list, s);
	while (s[i] && s)
	{
		if (s[i] == '%' && s[i + 1])
			ft_check(&list, s[++i], &result);
		else
			ft_putchar(s[i], &result);
		i++;
	}
	va_end (list);
	return (result);
}
