/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 14:04:41 by sleung            #+#    #+#             */
/*   Updated: 2017/02/17 15:51:55 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;
	unsigned char	*start;

	ptr = (unsigned char *)b;
	start = ptr;
	while (len-- > 0)
	{
		*ptr = (unsigned char)c;
		ptr++;
	}
	return (b);
}
