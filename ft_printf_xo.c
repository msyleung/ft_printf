/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_xo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 15:56:15 by sleung            #+#    #+#             */
/*   Updated: 2017/02/23 13:24:01 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

static int	ft_printf_xoxo(int n, char *str, t_struct *d)
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
//printf("\nspace: %i\nzero: %i\n", space, zero);
	handle_flags(d, &space, &zero, n);
	if (space && !d->minus && !d->zero && d->mw >= d->p)
		ti = write_spaces(space, tmp, 0);
	else if (space && !d->minus && d->zero && d->mw >= d->p && d->p > len)
		ti = write_spaces(space, tmp, 0);
	if (d->p == -1 && n == 0 && (d->conv == 'x' || d->conv == 'X' || !d->sharp))
		return (ft_putstrdel(&tmp, ti));
	handle_sharp(d, &tmp, &ti, n);
	ti = ((zero && len < d->p) || d->zero) ? write_zeros(zero, tmp, ti) : ti;
	while (*str != '\0')
		tmp[ti++] = *str++;
	ti = (space && d->minus) ? write_spaces(space, tmp, ti) : ti;
	return (ft_putstrdel(&tmp, ti));
}

int			ft_printf_o(int n, t_struct *d)
{
	char	*str;
	int		len;

	str = ft_itoa_base(n, 8);
	len = ft_printf_xoxo(n, str, d);
	ft_strdel(&str);
	return (len);
}

int			ft_printf_x(int n, t_struct *d)
{
	char	*str;
	int		len;

	len = -1;
	str = ft_itoa_base(n, 16);
	if (d->conv == 'x')
	{
		while (str[++len] != '\0')
		{
			if (str[len] >= 'A' && str[len] <= 'Z')
				str[len] += 32;
		}
	}
	len = ft_printf_xoxo(n, str, d);
//	ft_strdel(&str);
	return (len);
}
