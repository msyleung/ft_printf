/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 11:11:25 by sleung            #+#    #+#             */
/*   Updated: 2017/03/03 16:08:18 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_zeros(t_struct *d, int len, int z, int n)
{
	if ((d->plus || d->space) && d->zero && d->p < len && n > -1)
		z -= 1;
	else if (d->zero && d->sharp && n > 0)
		z -= 2;
	if (z && d->minus && d->p < len)
		z = 0;
	return (z);
}

void		handle_flags(t_struct *d, int *space, int *zero, int n)
{
	int	s;
	int	z;
	int len;

	len = ft_intlen(n);
	s = (*space > 0) ? *space : 0;
	z = *zero;
	if ((d->plus && n > 0) ||
			(d->zero && n > -1 && d->space && (d->mw - d->p != *space)))
		s -= 1;
	else if (!d->plus && d->space && (d->mw - d->p != *space)
			&& *space <= 0 && n > 0)
		s += 1;
	else if (d->sharp && n > 0 && (d->conv == 'x' || d->conv == 'X'))
		s -= 2;
	else if (d->sharp && n > 0 && (d->conv == 'o' || d->conv == 'O'))
		s -= 1;
	z = handle_zeros(d, len, z, n);
	if (d->zero && d->p >= len && n < 0)
	{
		z = (s > 0) ? s : d->p - (len - 1);
		s = 0;
	}
	*space = s;
	*zero = z;
}
