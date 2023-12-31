/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowarnie <lowarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:09:04 by lowarnie          #+#    #+#             */
/*   Updated: 2023/11/22 17:07:11 by lowarnie         ###   ########.fr       */
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
		}
		i++;
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
		ft_putnbr_base(va_arg(params, unsigned int), "0123456789", count);
	else if (letter == 'p')
		ft_putpointer(va_arg(params, unsigned long), count);
	else if (letter == 'X')
		ft_putnbr_base(va_arg(params, unsigned int), "0123456789ABCDEF",
			count);
	else if (letter == 'x')
		ft_putnbr_base(va_arg(params, unsigned int), "0123456789abcdef",
			count);
	else if (letter == '%')
		ft_putchar(letter, count);
}

size_t	ft_strlen(const char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

/* #include <stdio.h>

int	main(void)
{
    ft_printf("1 ma fonction : %c\n", '0');
    printf("1 la vraie fonction : %c\n", '0');
    ft_printf("2 ma fonction : %s\n", "bonjour");
    printf("2 la vraie fonction : %s\n", "bonjour");
    ft_printf("3 ma fonction : %d\n", 123456);
    printf("3 la vraie fonction : %d\n", 123456);
    ft_printf("4 ma fonction : %i\n", 123456);
    printf("4 la vraie fonction : %i\n", 123456);
    ft_printf("5 ma fonction : %u\n", -123456);
    printf("5 la vraie fonction : %u\n", -123456);
    ft_printf("6 ma fonction : %x\n", 123456);
    printf("6 la vraie fonction : %x\n", 123456);
    ft_printf("7 ma fonction : %X\n", 123456);
    printf("7 la vraie fonction : %X\n", 123456);
    ft_printf("8 ma fonction : %%\n");
    printf("8 la vraie fonction : %%\n");
    ft_printf("9 ma fonction : %p\n", "bonjour");
    printf("9 la vraie fonction : %p\n", "bonjour");
    return (0);
} */