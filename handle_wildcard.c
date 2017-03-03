/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wildcard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 18:40:57 by sleung            #+#    #+#             */
/*   Updated: 2017/03/02 19:04:00 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_wildcard(t_struct *d, t_format *f, va_list ap, int precision)
{
	int store;

	store = va_arg(ap, int);
	if (store < 0 && !precision)
	{
		d->minus += 1;
		store = -store;
	}
	else if (store < 0 && precision)
		store = 0;
	f->i++;
	return (store);
}
