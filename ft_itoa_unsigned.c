/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 13:18:36 by sleung            #+#    #+#             */
/*   Updated: 2017/02/26 17:10:17 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

char		*ft_itoa_unsigned(unsigned int value)
{
	char	*str;
	int		count;
	int		mod;

	count = 0;
	if (value < INT_MAX)
		return (str = ft_itoa_base(value, 10));
	if (!(str = (char *)malloc(sizeof(char) * 9 + 1)))
		return (NULL);
	while (count < 10)
	{
		mod = value % 10;
		str[9 - count] = mod + '0';
		value /= 10;
		count++;
	}
	str[10] = '\0';
	return (str);
}

static int	ft_itoa_base_uns_long_length(unsigned long value, int base)
{
	int	len;

	len = 0;
	if (base == 16)
		value = (unsigned int)value;
	while (value >= (unsigned long)base)
	{
		value /= base;
		len++;
	}
	return (len);
}

char		*ft_itoa_base_uns_long(unsigned long value, int base)
{
	int len;
	int count;
	char *str;

	count = 0;
	len = ft_itoa_base_uns_long_length(value, base);
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (count <= len)
	{
		str[len - count] = "0123456789ABCDEF"[value % base];
		value /= base;
		count++;
	}
	str[len + 1] = '\0';
	return (str);
}
