/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowarnie <lowarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:09:48 by lowarnie          #+#    #+#             */
/*   Updated: 2023/11/22 17:08:43 by lowarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, int *count)
{
	int	i;

	if (!str)
	{
		ft_putstr("(null)", count);
		return ;
	}
	i = 0;
	while (str[i])
	{
		ft_putchar(str[i], count);
		i++;
	}
}

void	ft_putnbr(int number, int *count)
{
	long int	nb;

	nb = number;
	if (nb < 0)
	{
		nb = nb * (-1);
		ft_putchar('-', count);
	}
	if (nb > 9)
		ft_putnbr(nb / 10, count);
	ft_putchar(nb % 10 + '0', count);
}

void	ft_putnbr_base(unsigned int nb, char *base, int *count)
{
	if (nb >= (unsigned int) ft_strlen(base))
		ft_putnbr_base(nb / ft_strlen(base), base, count);
	ft_putchar(base[nb % ft_strlen(base)], count);
}

void	ft_putnbr_base_ul(unsigned long nb, char *base, int *count)
{
	if (nb >= (unsigned long)ft_strlen(base))
	{
		ft_putnbr_base_ul(nb / ft_strlen(base), base, count);
	}
	ft_putchar(base[nb % ft_strlen(base)], count);
}

void	ft_putpointer(unsigned long arg, int *count)
{
	if (!arg)
		ft_putstr("(nil)", count);
	else
	{
		ft_putstr("0x", count);
		ft_putnbr_base_ul(arg, "0123456789abcdef", count);
	}
}
