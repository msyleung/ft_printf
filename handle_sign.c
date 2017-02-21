/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sign.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 11:15:12 by sleung            #+#    #+#             */
/*   Updated: 2017/02/21 15:37:58 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_sign(t_struct *d, char **tmp, char **str, int *ti)
{
	char	*cstr;
	char	*ctmp;
	int		j;

	cstr = *str;
	ctmp = *tmp;
	j = *ti;
	if (d->plus && *cstr != '-')
		ctmp[j++] = '+';
	else if (*cstr == '-')
	{
		ctmp[j++] = '-';
		cstr++;
	}
	*str = cstr;
	*tmp = ctmp;
	*ti = j;
}
