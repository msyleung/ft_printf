/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_wcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 12:59:16 by sleung            #+#    #+#             */
/*   Updated: 2017/03/03 14:36:58 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

static char	*unicode_to_utf8(wchar_t c, char **tmp, int *ti)
{
	char	*b;
	int		i;

	i = *ti;
	b = *tmp;
	if (c < (1 << 7))
		b[i++] = c;
	else if (c < (1 << 11))
	{
		b[i++] = ((c >> 6) + 0xC0);
		b[i++] = ((c & 0x3F) + 0x80);
	}
	else if (c < (1 << 16))
	{
		b[i++] = ((c >> 12) + 0xE0);
		b[i++] = (((c >> 6) & 0x3F) + 0x80);
		b[i++] = ((c & 0x3F) | 0x80);
	}
	else if (c < (1 << 21))
	{
		b[i++] = ((c >> 18) + 0xF0);
		b[i++] = (((c >> 12) & 0x3F) + 0x80);
		b[i++] = (((c >> 6) & 0x3F) + 0x80);
		b[i++] = ((c & 0x3F) + 0x80);
	}
	b[i] = '\0';
	*ti = i;
	return (b);
}

int	ft_printf_cc(wint_t c, t_struct *d)
{
	char	*tmp;
	int		spaces;
	int		len;
	int		ti;

	ti = 0;
	len = (d->mw > 0) ? d->mw : 1;
	tmp = ft_strnew(MB_CUR_MAX);
	spaces = d->mw - 1;
	if (d->minus == 0 && spaces > 0)
		ti = write_spaces(spaces, tmp, ti);
	tmp = unicode_to_utf8(c, &tmp, &ti);
	if (d->minus == 1 && spaces > 0)
		ti = write_spaces(spaces, tmp, ti);
	tmp[ti] = '\0';
	len = ft_putstr(tmp);
	if (c == 0)
		len += 1;
	ft_strdel(&tmp);
	return (len);
}
