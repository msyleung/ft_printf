/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 11:11:25 by sleung            #+#    #+#             */
/*   Updated: 2017/02/21 15:49:47 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_sharp(t_struct *d, char **tmp, int *ti)
{
	char	*ctmp;
	int		j;

	ctmp = *tmp;
	j = *ti;
	if (d->sharp)
	{
		ctmp[j++] = '0';
		ctmp[j++] = d->conv;
	}
	*tmp = ctmp;
	*ti = j;
}
