/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 13:17:00 by sleung            #+#    #+#             */
/*   Updated: 2017/02/26 15:56:07 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init_data(t_struct *d)
{
	d->conv = 0;
	d->flag = 0;
	d->sharp = 0;
	d->zero = 0;
	d->minus = 0;
	d->plus = 0;
	d->space = 0;
	d->mw = 0;
	d->p = 0;
	d->lm = 0;
}

static int	fill_data(va_list ap, t_struct *d)
{
	int	len;

	len = 0;
	check_flags(d);
	if (check_conv(d) == 1)
		len = read_data(ap, d);
	return (len);
}

static int	char_out(t_struct *d)
{
	write(1, &(d->fo[d->i]), 1);
	d->i++;
	return (1);
}

/*static void	erase_data(t_struct *d)
{
	ft_strdel(&d->fo);
	d->i = 0;
	d->conv = 0;
	d->flag = 0;
	d->zero = 0;
	d->minus = 0;
	d->plus = 0;
	d->space = 0;
	d->mw = 0;
	d->p = 0;
	d->lm = 0;
	free(d);
	d = NULL;
}*/

int			ft_printf(const char *format, ...)
{
	int				len;
	t_struct		*d;
	va_list			ap;

	len = 0;
	if (!(d = (t_struct *)malloc(sizeof(t_struct))))
		return (-1);
	d->i = 0;
	d->fo = (char *)format;
	va_start(ap, format);
	while (d->fo[d->i] != '\0')
	{
		if (d->fo[d->i] == '%')
		{
			init_data(d);
			if (!d->fo[++d->i])
				break ;
			len += fill_data(ap, d);
		}
		else
			len += char_out(d);
	}
	va_end(ap);
//	erase_data(d);
	return (len);
}
