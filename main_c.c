/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 16:12:47 by sleung            #+#    #+#             */
/*   Updated: 2017/02/19 17:45:44 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int ok = 0;
	int nok = 0;
	int	ret;
	int tru;

	if ((ret = ft_printf("%5c\n", 42)) == (tru = printf("%5c\n", 42)))
	{
		write(1, "***OK***\n", 9);
		ok++;
	}
	else
	{
		nok++;
		printf("yours: %i, true: %i\n\n", ret, tru);
	}	
	if ((ret = ft_printf("%-5c\n", 42)) == (tru = printf("%-5c\n", 42)))
	{
		write(1, "***OK***\n", 9);
		ok++;
	}
	else
	{
		nok++;
		printf("yours: %i, true: %i\n\n", ret, tru);
	}
	if ((ret = ft_printf("test %c is null\n", 0)) == (tru = printf("test %c is null\n", 0)))
	{
		write(1, "***OK***\n", 9);
		ok++;
	}
	else
	{
		nok++;
		printf("yours: %i, true: %i\n\n", ret, tru);
	}
	if ((ret = ft_printf("%2c\n", 0)) == (tru = printf("%2c\n", 0)))
	{
		write(1, "***OK***\n", 9);
		ok++;
	}
	else
	{
		nok++;
		printf("yours: %i, true: %i\n\n", ret, tru);
	}
	/*
	//third test
	if ((ret = ft_printf("3. %s\n", "this is a string")) == (tru = printf("3. %s\n", "this is a string")))
	{
		write(1, "***OK***\n", 9);
		ok++;
	}
	else
	{
		nok++;
		printf("yours: %i, true: %i\n", ret, tru);
	}
	//fourth test
	if ((ret = ft_printf("4. %s \n", "this is a string")) == (tru = printf("4. %s \n", "this is a string")))
	{
		write(1, "***OK***\n", 9);
		ok++;
	}
	else
	{
		nok++;
		printf("yours: %i, true: %i\n", ret, tru);
	}*/
}
