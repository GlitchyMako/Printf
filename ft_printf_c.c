/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalmeida <jalmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 19:02:26 by jalmeida          #+#    #+#             */
/*   Updated: 2021/03/30 19:02:26 by jalmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	padding(int n, char c)
{
	int count;

	count = 0;
	while (n-- > 0)
		count += ft_putchar(c);
	return (count);
}

int	ft_printf_c(t_flags *flags, va_list args)
{
	int		count;
	char	c;

	ft_printf_star(flags, args);
	c = va_arg(args, int);
	count = 0;
	if (flags->minus == 1)
		count = ft_putchar(c) + padding(flags->width - 1, ' ');
	else
		count = padding(flags->width - 1, ' ') + ft_putchar(c);
	return (count);
}
