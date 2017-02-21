/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 16:12:47 by sleung            #+#    #+#             */
/*   Updated: 2017/02/21 15:49:04 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	ret;
	int tru;

//t
	if ((ret = ft_printf("%x\n", 42)) == (tru = printf("%x\n", 42)))
		write(1, "***OK***\n", 9);
	else
		printf("yours: %i, true: %i\n~~~~~~~~~~~~~~~~~~\n", ret, tru);
//y
	if ((ret = ft_printf("%X\n", 42)) == (tru = printf("%X\n", 42)))
		write(1, "***OK***\n", 9);
	else
		printf("yours: %i, true: %i\n~~~~~~~~~~~~\n", ret, tru);
//first
	if ((ret = ft_printf("%x\n", 0)) == (tru = printf("%x\n", 0)))
		write(1, "***OK***\n", 9);
	else
		printf("yours: %i, true: %i\n~~~~~~~~~~~~~\n", ret, tru);
//secomd
	if ((ret = ft_printf("%X\n", 0)) == (tru = printf("%X\n", 0)))
		write(1, "***OK***\n", 9);
	else
		printf("yours: %i, true: %i\n~~~~~~~~~~~~~~~~\n", ret, tru);
//third
	if ((ret = ft_printf("%x\n", -42)) == (tru = printf("%x\n", -42)))
		write(1, "***OK***\n", 9);
	else
		printf("yours: %i, true: %i\n~~~~~~~~~~~~~~~~~~\n", ret, tru);
//fourth

	if ((ret = ft_printf("%#x\n", 42)) == (tru = printf("%#x\n", 42)))
		write(1, "***ok***\n", 9);
	else
		printf("yours: %i, true: %i\n~~~~~~~~~~~~~~~~~~~~\n", ret, tru);
//ther
	if ((ret = ft_printf("%#-.15x\n", 42)) == (tru = printf("%#-.15x\n", 42)))
		write(1, "***ok***\n", 9);
	else
		printf("yours: %i, true: %i\n~~~~~~~~~~~~~~~~~~~~\n", ret, tru);
//ther
	if ((ret = ft_printf("%.x\n", 0)) == (tru = printf("%.x\n", 0)))
		write(1, "***ok***\n", 9);
	else
		printf("yours: %i, true: %i\n~~~~~~~~~~~~~~~~~~~~\n", ret, tru);
}
