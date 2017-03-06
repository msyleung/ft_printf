/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_null.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 13:24:59 by sleung            #+#    #+#             */
/*   Updated: 2017/03/05 18:47:52 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

static int	write_null_conv_c(t_struct *d, char c, int ti)
{
	char	*tmp;
	int		space;

	c = 0;
	if (d->mw && !d->zero)
	{
		space = d->mw - 1;
		tmp = ft_strnew(d->mw);
		ti = write_spaces(space, tmp, 0);
		tmp[ti++] = 0;
		return (ft_putstrdel(&tmp, ti));
	}
	write(1, &c, 1);
	return (1);
}

int			write_null(t_struct *d)
{
	char	*tmp;
	int		ti;
	char	c;

	c = 0;
	if (d->conv == 'c' || d->conv == 'C')
		return (write_null_conv_c(d, c, 0));
	if (!d->zero && (d->conv == 's' || d->conv == 'S') && d->p != -1)
	{
		tmp = ft_strjoin("(null)", "");
		ti = 6;
	}
	else
	{
		tmp = ft_strnew(d->mw);
		ti = (d->zero) ? write_zeros(d->mw, tmp, 0) :
			write_spaces(d->mw, tmp, 0);
	}
	return (ft_putstrdel(&tmp, ti));
}
