/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaoud <msaoud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:22:25 by msaoud            #+#    #+#             */
/*   Updated: 2022/01/11 03:31:58 by msaoud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_check(va_list ap, const char *format, int *count, ...)
{
	if (*format == 'c')
		ft_putchar(va_arg(ap, int), count);
	else if (*format == 's')
		ft_putstr(va_arg(ap, char *), count);
	else if (*format == 'd' || *format == 'i')
		ft_putnbr(va_arg(ap, int), count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;
	int		i;

	i = -1;
	count = 0;
	va_start(ap, format);
	while (format[++i])
	{
		if (format[i] == '%')
		{
			i++;
			ft_check(ap, &format[i], &count);
		}
		else
			ft_putchar(format[i], &count);
	}
	va_end(ap);
	return (count);
}
