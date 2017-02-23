/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 15:56:56 by sleung            #+#    #+#             */
/*   Updated: 2017/02/23 13:09:02 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_pt(t_struct *d)
{
	char	*tmp;
	int		spaces;
	int		len;
	int		ti;

	ti = 0;
	len = (d->mw > 0) ? d->mw : 1;
	tmp = ft_strnew(len);
	spaces = d->mw - 1;
	if (d->minus == 0 && spaces > 0)
		ti = write_spaces(spaces, tmp, ti);
	tmp[ti++] = '%';
	if (d->minus == 1 && spaces > 0)
		ti = write_spaces(spaces, tmp, ti);
	return (ft_putstrdel(&tmp, ti));
}
