/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 14:22:31 by sleung            #+#    #+#             */
/*   Updated: 2017/02/17 15:51:43 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_itoa_base_length(unsigned int value, int base)
{
	int	len;

	len = ((int)value < 0 && base == 10) ? 1 : 0;
	value = ((int)value < 0 && base == 10) ? -value : value;
	while (value >= (unsigned int)base)
	{
		value /= base;
		len++;
	}
	return (len);
}

char		*ft_itoa_base(unsigned int value, int base)
{
	int		neg;
	int		len;
	int		count;
	char	*str;

	count = 0;
	if (base < 2 || base > 16)
		return (NULL);
	len = ft_itoa_base_length(value, base);
	neg = ((int)value < 0 && base == 10) ? 1 : 0;
	value = ((int)value < 0 && base == 10) ? -value : value;
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (count <= len)
	{
		str[len - count] = "0123456789ABCDEF"[value % base];
		value /= base;
		count++;
	}
	if (neg)
		str[0] = '-';
	str[len + 1] = '\0';
	return (str);
}
