/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 11:11:25 by sleung            #+#    #+#             */
/*   Updated: 2017/02/23 12:48:50 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_flags(t_struct *d, int *space, int *zero, int n)
{
	int	s;
	int	z;
	int len;

	len = ft_intlen(n);
	s = (*space > 0) ? *space : 0;
	z = *zero;
	if (d->plus && n > 0)
		s -= 1;
	else if (!d->plus && d->space && n > 0 && (d->mw - d->p != *space))
		s += 1;
	else if (d->sharp && n > 0 && (d->conv == 'x' || d->conv == 'X'))
		s -= 2;
	else if (d->sharp && n > 0 && (d->conv == 'o' || d->conv == 'O'))
		s -= 1;
	if (d->plus && d->zero && n > 0 && d->p < len)
		z -= 1;
	else if (d->zero && d->sharp && n > 0)
		z -= 2;
	if (*zero && d->minus && d->p < len)
		z = 0;
	*space = s;
	*zero = z;
}
