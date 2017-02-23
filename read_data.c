/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 15:42:21 by sleung            #+#    #+#             */
/*   Updated: 2017/02/23 13:48:44 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int read_data2(va_list ap, t_struct *d)
{
	int len;

	len = 0;
	if (d->conv == 'u')
		len += ft_printf_u(va_arg(ap, unsigned int), d);
//	else if (d->conv == 'U')
//		len += ft_printf_cu(va_arg(ap, unsigned long), d);	
	else if (d->conv == 'X' || d->conv == 'x')
		len += ft_printf_x(va_arg(ap, int), d);
	else if (d->conv == 'c')
		len += ft_printf_c(va_arg(ap, int), d);
//	else if (d->conv == 'C')
//		len += ft_printf_cc(va_arg(ap, int), d);
	else if (d->conv == '%')
		len += ft_printf_pt(d);
	return (len);
}

int			read_data(va_list ap, t_struct *d)
{
	int len;

	len = 0;
	if (d->conv == 's')
		len += ft_printf_s(va_arg(ap, char *), d);
//	else if (d->conv == 'S')
//		len += ft_printf_cs(va_arg(ap, char *), d);
//	else if (d->conv == 'p')
//		len += ft_printf_p(va_arg(ap, void *), d);
	else if (d->conv == 'i' || d->conv == 'd')
		len += ft_printf_i(va_arg(ap, int), d);
//	else if (d->conv == 'D')
//		len += ft_printf_cd(va_arg(ap, void *), d);
	else if (d->conv == 'o')
		len += ft_printf_o(va_arg(ap, int), d);
//	else if (d->conv == 'O')
//		len += ft_printf_co(va_arg(ap, long), d);
	else
		len += read_data2(ap, d);
	d->i++;
	return (len);
}
