/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalmeida <jalmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 19:02:49 by jalmeida          #+#    #+#             */
/*   Updated: 2021/03/30 19:02:49 by jalmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_pct(t_flags *flags, va_list args)
{
	int		count;

	ft_printf_star(flags, args);
	count = 0;
	if (flags->minus)
		count += ft_putchar('%');
	count += padding(flags->width - 1, flags->zero ? '0' : ' ');
	if (!flags->minus)
		count += ft_putchar('%');
	return (count);
}
