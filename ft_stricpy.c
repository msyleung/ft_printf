/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stricpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 15:51:18 by sleung            #+#    #+#             */
/*   Updated: 2017/03/06 13:38:23 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_stricpy(char *dst, int *i, const char *src)
{
	int	j;
	int n;

	n = 0;
	j = *i;
	while (src[n] != '\0')
		dst[j++] = src[n++];
	dst[j] = '\0';
	*i = j;
	return (dst);
}
