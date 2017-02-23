/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 11:11:25 by sleung            #+#    #+#             */
/*   Updated: 2017/02/21 16:16:28 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_sharp(t_struct *d, char **tmp, int *ti, int n)
{
	char	*ctmp;
	int		j;

	ctmp = *tmp;
	j = *ti;
	if (d->sharp && n != 0)
	{
		ctmp[j++] = '0';
		if (d->conv == 'x' || d->conv == 'X')
			ctmp[j++] = d->conv;
	}
	*tmp = ctmp;
	*ti = j;
}
