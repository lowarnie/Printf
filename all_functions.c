/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowarnie <lowarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:09:48 by lowarnie          #+#    #+#             */
/*   Updated: 2023/11/20 10:28:47 by lowarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putstr(char *str, int *count)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i], count);
		i++;
	}
}
void	ft_putnbr(int number, *count)
{
	long int	nb;
	
	number = nb;
	if (nb < 0)
	{
		nb = nb * (-1);
		ft_putchar('-', count);
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10, count);
		ft_putchar(nb % 10 + '0', count);
	}
}
void	ft_putnbr_base(unsigned int number, char *base, int *count)
{
	
}
void	ft_putnbr_base_ul(unsigned long number, char *base, int *count)
{
	
}
void	ft_putpointer(unsigned long arg, int *count)
{
	
}