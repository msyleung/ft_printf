/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 13:18:36 by sleung            #+#    #+#             */
/*   Updated: 2017/02/23 13:19:17 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_unsigned(unsigned int value)
{
	char	*str;
	int		count;
	int		mod;

	count = 0;
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
