/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tonarrow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 17:58:25 by sleung            #+#    #+#             */
/*   Updated: 2017/03/05 12:58:08 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	convert_unicode(wchar_t c, char *dst, int j)
{
	if (c < (1 << 7))
		dst[j++] = c;
	else if (c < (1 << 11))
	{
		dst[j++] = ((c >> 6) + 0xC0);
		dst[j++] = ((c & 0x3F) + 0x80);
	}
	else if (c < (1 << 16))
	{
		dst[j++] = ((c >> 12) + 0xE0);
		dst[j++] = (((c >> 6) & 0x3F) + 0x80);
		dst[j++] = ((c & 0x3F) | 0x80);
	}
	else if (c < (1 << 21))
	{
		dst[j++] = ((c >> 18) + 0xF0);
		dst[j++] = (((c >> 12) & 0x3F) + 0x80);
		dst[j++] = (((c >> 6) & 0x3F) + 0x80);
		dst[j++] = ((c & 0x3F) + 0x80);
	}
	return (j);
}

int			ft_tonarrow(wchar_t *str, char *dst, int dlen, int ti)
{
	int		i;
	int		j;
	wchar_t	c;

	j = ti;
	i = 0;
	while (str[i] != '\0' && (i < dlen - 1))
	{
		c = str[i];
		j = convert_unicode(c, dst, j);
		i++;
	}
	dst[j] = '\0';
	return (j);
}
