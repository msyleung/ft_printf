/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_null.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 13:24:59 by sleung            #+#    #+#             */
/*   Updated: 2017/03/05 14:18:59 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_null(t_struct *d)
{
	char	*tmp;
	int		ti;
	char	c;

	if (d->conv == 'c' || d->conv == 'C')
	{
		c = 0;
		write(1, &c, 1);
		return (1);
	}
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
