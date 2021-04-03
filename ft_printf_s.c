/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalmeida <jalmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 19:02:58 by jalmeida          #+#    #+#             */
/*   Updated: 2021/03/30 21:33:11 by jalmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		fucknorm(t_flags *flags, int pad_size, int size, char *str)
{
	int		count;

	count = 0;
	if (flags->width > ft_strlen(str) && flags->zero == 1 && flags->point != 0)
		count += padding(pad_size, '0');
	else
		count += padding(pad_size, ' ');
	while (size-- && *str)
		count += ft_putchar(*str++);
	return (count);
}

int				ft_printf_s(t_flags *flags, va_list args)
{
	int		count;
	char	*str;
	int		size;
	int		pad_size;

	ft_printf_star(flags, args);
	str = va_arg(args, char *);
	count = 0;
	if (str == NULL)
		str = "(null)";
	size = (flags->point > ft_strlen(str) || flags->point == -1)
			? ft_strlen(str) : flags->point;
	pad_size = flags->width - size;
	if (flags->width > ft_strlen(str) && flags->zero == 1)
		return (fucknorm(flags, pad_size, size, str));
	if (!flags->minus)
		count += padding(pad_size, ' ');
	while (size-- && *str)
		count += ft_putchar(*str++);
	if (flags->minus)
		count += padding(pad_size, ' ');
	return (count);
}
