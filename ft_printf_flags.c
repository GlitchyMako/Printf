/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalmeida <jalmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 19:02:40 by jalmeida          #+#    #+#             */
/*   Updated: 2021/03/30 19:02:40 by jalmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_star(t_flags *flags, va_list args)
{
	if (flags->star == 1)
		flags->width = va_arg(args, int);
	else if (flags->star == 2)
		flags->point = va_arg(args, int);
	else if (flags->star == 3)
	{
		flags->width = va_arg(args, int);
		flags->point = va_arg(args, int);
	}
	if (flags->width < 0)
	{
		flags->width = flags->width * -1;
		flags->minus = 1;
		flags->zero = 0;
	}
	if (flags->point < 0)
		flags->point = -1;
}

int		ft_isconversion(t_flags *flags, va_list args)
{
	int count;

	count = 0;
	if (flags->type == 'd' || flags->type == 'i')
		count += ft_printf_d(flags, args);
	else if (flags->type == 'x' || flags->type == 'X')
		count += ft_printf_x(flags, args);
	else if (flags->type == 'c')
		count += ft_printf_c(flags, args);
	else if (flags->type == 's')
		count += ft_printf_s(flags, args);
	else if (flags->type == 'p')
		count += ft_printf_p(flags, args);
	else if (flags->type == 'u')
		count += ft_printf_u(flags, args);
	else if (flags->type == '%')
		count += ft_printf_pct(flags, args);
	else
		flags->len = 0;
	return (count);
}

int		ft_putflags(int condition, char c)
{
	int count;

	count = 0;
	while (condition-- > 0)
		count += ft_putchar(c);
	return (count);
}
