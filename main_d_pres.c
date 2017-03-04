/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 16:12:47 by sleung            #+#    #+#             */
/*   Updated: 2017/03/03 16:02:35 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	ret;
	int tru;

	if ((ret = ft_printf("%d\n", 21474836)) == (tru = printf("%d\n", 21474836)))
		write(1, "***OK***\n", 9);
	else
		printf("yours: %i, true: %i\n~~~~~~~~~~~~~~~~~~\n", ret, tru);
//t
	if ((ret = ft_printf("%-5d\n", 42)) == (tru = printf("%-5d\n", 42)))
		write(1, "***OK***\n", 9);
	else
		printf("yours: %i, true: %i\n~~~~~~~~~~~~~~~~~~\n", ret, tru);
//y
	if ((ret = ft_printf("%05d\n", -42)) == (tru = printf("%05d\n", -42)))
		write(1, "***OK***\n", 9);
	else
		printf("yours: %i, true: %i\n~~~~~~~~~~~~\n", ret, tru);
//first
	if ((ret = ft_printf("%.10d\n", 4242)) == (tru = printf("%.10d\n", 4242)))
		write(1, "***OK***\n", 9);
	else
		printf("yours: %i, true: %i\n~~~~~~~~~~~~~\n", ret, tru);
//secomd
	if ((ret = ft_printf("%.2d\n", 4242)) == (tru = printf("%.2d\n", 4242)))
		write(1, "***OK***\n", 9);
	else
		printf("yours: %i, true: %i\n~~~~~~~~~~~~~~~~\n", ret, tru);
//third
	if ((ret = ft_printf("%4.15d\n", 42)) == (tru = printf("%4.15d\n", 42)))
		write(1, "***OK***\n", 9);
	else
		printf("yours: %i, true: %i\n~~~~~~~~~~~~~~~~~~\n", ret, tru);
//fourth
	if ((ret = ft_printf("%10.5d\n", 4242)) == (tru = printf("%10.5d\n", 4242)))
		write(1, "***ok***\n", 9);
	else
		printf("yours: %i, true: %i\n~~~~~~~~~~~~~~~~~~~~\n", ret, tru);
//fifth??
	if ((ret = ft_printf("testomg %.10d\n", -4242)) == (tru = printf("testomg %.10d\n", -4242)))
		write(1, "***ok***\n", 9);
	else
		printf("yours: %i, true: %i\n~~~~~~~~~~~~~~~~~~~~\n", ret, tru);
//ther
	if ((ret = ft_printf("%15.4d\n", 424242)) == (tru = printf("%15.4d\n", 424242)))
		write(1, "***ok***\n", 9);
	else
		printf("yours: %i, true: %i\n~~~~~~~~~~~~~~~~~~~~\n", ret, tru);
//ther
	if ((ret = ft_printf("%15.4d\n", -42)) == (tru = printf("%15.4d\n", -42)))
		write(1, "***ok***\n", 9);
	else
		printf("yours: %i, true: %i\n~~~~~~~~~~~~~~~~~~~~\n", ret, tru);
//fucking zero
	if ((ret = ft_printf("%.d, %.0d\n", 0, 0)) == (tru = printf("%.d, %.0d\n", 0, 0)))
		write(1, "***ok***\n", 9);
	else
		printf("yours: %i, true: %i\n~~~~~~~~~~~~~~~~~~~~\n", ret, tru);
//AGAIN
	if ((ret = ft_printf("%05.2d\n", 0)) == (tru = printf("%05.2d\n", 0)))
		write(1, "***ok***\n", 9);
	else
		printf("yours: %i, true: %i\n~~~~~~~~~~~~~~~~~~~~\n", ret, tru);
//AGAIN
	if ((ret = ft_printf("%05.2d\n", 1)) == (tru = printf("%05.2d\n", 1)))
		write(1, "***ok***\n", 9);
	else
		printf("yours: %i, true: %i\n~~~~~~~~~~~~~~~~~~~~\n", ret, tru);
//fucking zero
	if ((ret = ft_printf("//%.d, %.0d\n", 42, 43)) == (tru = printf("//%.d, %.0d\n", 42, 43)))
		write(1, "***ok***\n", 9);
	else
		printf("yours: %i, true: %i\n~~~~~~~~~~~~~~~~~~~~\n", ret, tru);
//fucking zero
	if ((ret = ft_printf("test |%5.d| |%5.0d|\n", 500, 0)) == (tru = printf("test |%5.d| |%5.0d|\n", 500, 0)))
		write(1, "***ok***\n", 9);
	else
		printf("yours: %i, true: %i\n~~~~~~~~~~~~~~~~~~~~\n", ret, tru);


//d->zero && plus
	if ((ret = ft_printf("num: %+05d\n", 88)) == (tru = printf("num: %+05d\n", 88)))
		write(1, "***ok***\n", 9);
	else
		printf("yours: %i, true: %i\n~~~~~~~~~~~~~~~~~~~~\n", ret, tru);
//d->plus
	if ((ret = ft_printf("num: %+5d\n", 42)) == (tru = printf("num: %+5d\n", 42)))
		write(1, "***ok***\n", 9);
	else
		printf("yours: %i, true: %i\n~~~~~~~~~~~~~~~~~~~~\n", ret, tru);
//zero && bigger pres than mw
	if ((ret = ft_printf("num: %01.5d\n", 42)) == (tru = printf("num: %01.5d\n", 42)))
		write(1, "***ok***\n", 9);
	else
		printf("yours: %i, true: %i\n~~~~~~~~~~~~~~~~~~~~\n", ret, tru);
//space & bigger pres than mw
	if ((ret = ft_printf("num: %01.5d\n", 42)) == (tru = printf("num: %01.5d\n", 42)))
		write(1, "***ok***\n", 9);
	else
		printf("yours: %i, true: %i\n~~~~~~~~~~~~~~~~~~~~\n", ret, tru);
//+ & bigger pres than mw
	if ((ret = ft_printf("num: %+01.6d\n", 1111)) == (tru = printf("num: %+01.6d\n", 1111)))
		write(1, "***ok***\n", 9);
	else
		printf("yours: %i, true: %i\n~~~~~~~~~~~~~~~~~~~~\n", ret, tru);
//
	if ((ret = ft_printf("num: |%-10.5d|\n", 9090)) == (tru = printf("num: |%-10.5d|\n", 9090)))
		write(1, "***ok***\n", 9);
	else
		printf("yours: %i, true: %i\n~~~~~~~~~~~~~~~~~~~~\n", ret, tru);
	//test
	if ((ret = ft_printf("num: |% 03d|\n", 0)) == (tru = printf("num: |% 03d|\n", 0)))
		write(1, "***ok***\n", 9);
	else
		printf("yours: %i, true: %i\n~~~~~~~~~~~~~~~~~~~~\n", ret, tru);
	//test
	if ((ret = ft_printf("num: |%010d|\n", 42)) == (tru = printf("num: |%010d|\n", 42)))
		write(1, "***ok***\n", 9);
	else
		printf("yours: %i, true: %i\n~~~~~~~~~~~~~~~~~~~~\n", ret, tru);
	if ((ret = ft_printf("num: |%20.15d|\n", 54321)) == (tru = printf("num: |%20.15d|\n", 54321)))
		write(1, "***ok***\n", 9);
	else
		printf("yours: %i, true: %i\n~~~~~~~~~~~~~~~~~~~~\n", ret, tru);
	//blank
	if ((ret = ft_printf("num: |%5.d|\n", 42)) == (tru = printf("num: |%5.d|\n", 42)))
		write(1, "***ok***\n", 9);
	else
		printf("yours: %i, true: %i\n~~~~~~~~~~~~~~~~~~~~\n", ret, tru);
	//mew
	if ((ret = ft_printf("num: |% 4.5i|\n", 42)) == (tru = printf("num: |% 4.5i|\n", 42)))
		write(1, "***ok***\n", 9);
	else
		printf("yours: %i, true: %i\n~~~~~~~~~~~~~~~~~~~~\n", ret, tru);
	//zero
	if ((ret = ft_printf("num: |%04.2i|\n", 42)) == (tru = printf("num: |%04.2i|\n", 42)))
		write(1, "***ok***\n", 9);
	else
		printf("yours: %i, true: %i\n~~~~~~~~~~~~~~~~~~~~\n", ret, tru);
	//space
	if ((ret = ft_printf("num: |%4i|\n", 42)) == (tru = printf("num: |%4i|\n", 42)))
		write(1, "***ok***\n", 9);
	else
		printf("yours: %i, true: %i\n~~~~~~~~~~~~~~~~~~~~\n", ret, tru);
	if ((ret = ft_printf("num: |%03.2i|\n", -1)) == (tru = printf("num: |%03.2i|\n", -1)))
		write(1, "***ok***\n", 9);
	else
		printf("yours: %i, true: %i\n~~~~~~~~~~~~~~~~~~~~\n", ret, tru);
	if ((ret = ft_printf("num: |%05.9i|\n", -420)) == (tru = printf("num: |%05.9i|\n", -420)))
		write(1, "***ok***\n", 9);
	else
		printf("yours: %i, true: %i\n~~~~~~~~~~~~~~~~~~~~\n", ret, tru);
//d->space && mw = 4 && p == 0  no space
	if ((ret = ft_printf("num: |% 4i|\n", 42)) == (tru = printf("num: |% 4i|\n", 42)))
		write(1, "***ok***\n", 9);
	else
		printf("yours: %i, true: %i\n~~~~~~~~~~~~~~~~~~~~\n", ret, tru);
//no space w/ mw = 4 && p == 0
	if ((ret = ft_printf("num: |%4i|\n", 42)) == (tru = printf("num: |%4i|\n", 42)))
		write(1, "***ok***\n", 9);
	else
		printf("yours: %i, true: %i\n~~~~~~~~~~~~~~~~~~~~\n", ret, tru);
//d->space .. mw = 0 && p = 0;  needs space
	if ((ret = ft_printf("num: |% d|\n", 42)) == (tru = printf("num: |% d|\n", 42)))
		write(1, "***ok***\n", 9);
	else
		printf("yours: %i, true: %i\n~~~~~~~~~~~~~~~~~~~~\n", ret, tru);
//d->space && neg
	if ((ret = ft_printf("num: |% d|\n", -42)) == (tru = printf("num: |% d|\n", -42)))
		write(1, "***ok***\n", 9);
	else
		printf("yours: %i, true: %i\n~~~~~~~~~~~~~~~~~~~~\n", ret, tru);
//d->space w/ mw & p
	if ((ret = ft_printf("num: |% 10.5d|\n", 42)) == (tru = printf("num: |% 10.5d|\n", 42)))
		write(1, "***ok***\n", 9);
	else
		printf("yours: %i, true: %i\n~~~~~~~~~~~~~~~~~~~~\n", ret, tru);
//d->space .. mw = 4 && p = 5;  needs space
	if ((ret = ft_printf("num: |% 4.5d|\n", 42)) == (tru = printf("num: |% 4.5d|\n", 42)))
		write(1, "***ok***\n", 9);
	else
		printf("yours: %i, true: %i\n~~~~~~~~~~~~~~~~~~~~\n", ret, tru);
}
