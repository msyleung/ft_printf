/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 15:56:56 by sleung            #+#    #+#             */
/*   Updated: 2017/03/03 16:19:33 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf_pt(t_struct *d)
{
	char	*tmp;
	int		spaces;
	int		zero;
	int		len;
	int		ti;

	ti = 0;
	len = (d->mw > 0) ? d->mw : 1;
	tmp = ft_strnew(len);
	spaces = (!d->zero) ? d->mw - 1 : 0;
	zero = (!d->zero) ? 0 : d->mw - 1;
	if (d->minus == 0 && spaces > 0)
		ti = write_spaces(spaces, tmp, ti);
	else if (d->zero)
		ti = write_zeros(zero, tmp, ti);
	tmp[ti++] = '%';
	if (d->minus == 1 && spaces > 0)
		ti = write_spaces(spaces, tmp, ti);
	return (ft_putstrdel(&tmp, ti));
}

static int	ft_printf_nullptr(t_struct *d, int ti)
{
	char *tmp; 

	if (d->p == -1)
	{
		tmp = ft_strjoin("0x", "");
		return (ft_putstrdel(&tmp, 2));
	}
	else if (d->p > 0)
	{
		tmp = ft_strnew(d->p + 2);
		tmp = ft_strjoin("0x", "");
		ti = 2;
		while (d->p-- > 0)
			tmp[ti++] = '0';
		return (ft_putstrdel(&tmp, ti));
	}
	tmp = ft_strjoin("0x0", "");
	return (ft_putstrdel(&tmp, 3));
}

static int	ft_printf_ptr(t_struct *d, char *str, int n)
{
	char	*tmp;
	int		len;
	int		space;
	int		zero;
	int		ti;

	ti = 0;
	len = ft_strlen(str);
	tmp = ft_strnew((len + d->mw > d->p) ? len + d->mw : d->p);
	space = count_spaces_int(d, len, n) - 2;
	zero = (d->p > len) ? count_zeros(d, len, n) : space;
	if (space && d->mw >= d->p)
		ti = write_spaces(space, tmp, 0);
	tmp[ti++] = '0';
	tmp[ti++] = 'x';
	ti = ((zero && len < d->p) || d->zero) ? write_zeros(zero, tmp, ti) : ti;
	while (*str != '\0')
		tmp[ti++] = *str++;
	return (ft_putstrdel(&tmp, ti));
}

int			ft_printf_p(void *ptr, t_struct *d)
{
	char	*str;
	char	*tmp;
	long	n;
	int		ti;

	ti = -1;
	n = (long)ptr;
	if (n == 0)
		return (ft_printf_nullptr(d, ti));
	tmp = ft_itoa_base(n, 16);
	while (tmp[++ti] != '\0')
	{
		if (tmp[ti] >= 'A' && tmp[ti] <= 'Z')
			tmp[ti] += 32;
	}
	if (d->p)
		return (ft_printf_ptr(d, tmp, n));
	str = ft_strjoin("0x", tmp);
	ti = ft_printf_s(str, d);
	ft_strdel(&str);
	ft_strdel(&tmp);
	return (ti);
}
