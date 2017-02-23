/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_id.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 15:55:52 by sleung            #+#    #+#             */
/*   Updated: 2017/02/21 15:38:48 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_id(int n, char *str, t_struct *d)
{
	char	*tmp;
	int		zero;
	int		space;
	int		ti;
	int		len;

	ti = 0;
	len = (str[0] == 0) ? 0 : ft_strlen(str);
	tmp = ft_strnew((len > d->p) ? len + d->mw : d->p);
	space = count_spaces_int(d, len, n);
	zero = (!d->zero || (d->p > len)) ? count_zeros(d, len, n) : space;
	handle_flags(d, &space, &zero, n);
	if (space && !d->minus && !d->zero && d->mw >= d->p)
		ti = write_spaces(space, tmp, 0);
	else if (space && !d->minus && d->zero && d->mw >= d->p && d->p > len)
		ti = write_spaces(space, tmp, 0);
	if (d->p == -1 && n == 0)
		return (ft_putstrdel(&tmp, ti));
	handle_sign(d, &tmp, &str, &ti);
	ti = ((zero && len < d->p) || d->zero) ? write_zeros(zero, tmp, ti) : ti;
	while (*str != '\0')
		tmp[ti++] = *str++;
	ti = (space && d->minus) ? write_spaces(space, tmp, ti) : ti;
	return (ft_putstrdel(&tmp, ti));
}

int			ft_printf_i(int n, t_struct *d)
{
	char	*str;
	int		len;

	str = ft_itoa_base(n, 10);
	len = ft_printf_id(n, str, d);
	ft_strdel(&str);
	return (len);
}