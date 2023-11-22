/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowarnie <lowarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:08:22 by lowarnie          #+#    #+#             */
/*   Updated: 2023/11/22 16:36:14 by lowarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);

size_t	ft_strlen(const char *str);

void	ft_putstr(char *str, int *count);
void	ft_putchar(char c, int *count);
void	ft_putnbr(int number, int *count);
void	ft_putnbr_base(unsigned int nb, char *base, int *count);
void	ft_putnbr_base_ul(unsigned long nb, char *base, int *count);
void	ft_putpointer(unsigned long arg, int *count);
void	ft_letter(char letter, va_list params, int *count);

#endif