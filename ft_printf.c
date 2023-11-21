/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowarnie <lowarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:09:04 by lowarnie          #+#    #+#             */
/*   Updated: 2023/11/20 11:23:55 by lowarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	params;
	int		i;
	int		count;

	va_start(params, format);
	i = 0;
	count = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			ft_letter(format[i], params, &count);
		}
		else
		{
			ft_putchar(format[i], &count);
			i++;
		}
	}
	va_end(params);
	return (count);
}

void	ft_putchar(char c, int *count)
{
	*count += write(1, &c, 1);
}

void	ft_letter(char letter, va_list params, int *count)
{
	if (letter == 'c')
		ft_putchar(va_arg(params, int), count);
	else if (letter == 's')
		ft_putstr(va_arg(params, char *), count);
	else if (letter == 'd' || letter == 'i')
		ft_putnbr(va_arg(params, int), count);
	else if (letter == 'u')
		ft_putnbr_base(va_arg(params, unsigned long), "0123456789", count);
	else if (letter == 'p')
		ft_putpointer(va_arg(params, unsigned long), count);
	else if (letter == 'X')
		ft_putnbr_base(va_arg(params, unsigned long), "0123456789ABCDEF", count);
	else if (letter == 'x')
		ft_putnbr_base(va_arg(params, unsigned long), "0123456789abcdef", count);
	else if (letter == '%')
		ft_putchar(letter, count);
}
