/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 13:34:07 by sleung            #+#    #+#             */
/*   Updated: 2017/02/27 17:48:03 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	get_flags(t_struct *d)
{
	while (d->fo[d->i] == '#' || d->fo[d->i] == '0' || d->fo[d->i] == '-'
			|| d->fo[d->i] == ' ' || d->fo[d->i] == '+')
	{
		if (d->fo[d->i] == '#')
			d->sharp += 1;
		else if (d->fo[d->i] == '0')
			d->zero += 1;
		else if (d->fo[d->i] == '-')
			d->minus += 1;
		else if (d->fo[d->i] == ' ')
			d->space += 1;
		else if (d->fo[d->i] == '+')
			d->plus += 1;
		d->i++;
	}
}

static void	get_precision(t_struct *d)
{
	char	*pstr;
	int		n;

	n = 0;
	d->i++;
	pstr = ft_strnew(10);
	while (d->fo[d->i] >= '0' && d->fo[d->i] <= '9')
		pstr[n++] = d->fo[d->i++];
	if (!(d->p = ft_atoi(pstr)))
		d->p = -1;
	ft_strdel(&pstr);
}

static void	get_minwidth(t_struct *d)
{
	char	*mwstr;
	int		n;

	n = 0;
	mwstr = ft_strnew(10);
	while (d->fo[d->i] >= '0' && d->fo[d->i] <= '9')
		mwstr[n++] = d->fo[d->i++];
	d->mw = ft_atoi(mwstr);
	ft_strdel(&mwstr);
}

static void get_length_modifier(t_struct *d)
{
	d->lm = d->fo[d->i++];
	if (d->lm == 'h' && d->fo[d->i] == 'h')
	{
		d->lm = 'H';
		d->i++;
	}
	else if (d->lm == 'l' && d->fo[d->i] == 'l')
	{
		d->lm = 'L';
		d->i++;
	}
}

void		check_flags(t_struct *d)
{
	d->flag = (d->fo[d->i] == '#' || d->fo[d->i] == '0' || d->fo[d->i] == '-'
			|| d->fo[d->i] == '+' || d->fo[d->i] == ' ') ? 1 : 0;
	if (d->flag)
		get_flags(d);
	d->mw = (d->fo[d->i] >= '0' && d->fo[d->i] <= '9') ? 1 : 0;
	if (d->mw)
		get_minwidth(d);
	d->p = (d->fo[d->i] == '.') ? 1 : 0;
	if (d->p)
		get_precision(d);
	if (d->fo[d->i] == 'h' || d->fo[d->i] == 'l' || d->fo[d->i] == 'j'
			|| d->fo[d->i] == 'z')
		get_length_modifier(d);
}
