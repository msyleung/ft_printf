/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 16:12:47 by sleung            #+#    #+#             */
/*   Updated: 2017/02/19 15:21:06 by sleung           ###   ########.fr       */
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

	if (ft_printf("1. testing\n") == printf("1. testing\n"))
	{
		write(1, "***OK***\n", 9);
		ok++;
	}
	else
		nok++;
	//second test
	if ((ret = ft_printf("%s\n", "abc")) == (tru = printf("%s\n", "abc")))
	{
		write(1, "***OK***\n", 9);
		ok++;
	}
	else
	{
		nok++;
		printf("yours: %i, true: %i\n\n", ret, tru);
	}
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
	}
	//fifth test
	if ((ret = ft_printf("5. %s  \n", "this is a string")) == (tru = printf("5. %s  \n", "this is a string")))
	{
		write(1, "***OK***\n", 9);
		ok++;
	}
	else
	{
		nok++;
		printf("yours: %i, true: %i\n", ret, tru);
	}
	//sixth test
	if ((ret = ft_printf("6. this is a %s\n", "string")) == (tru = printf("6. this is a %s\n", "string")))
	{
		write(1, "***OK***\n", 9);
		ok++;
	}
	else
	{
		nok++;
		printf("yours: %i, true: %i\n", ret, tru);
	}
	//seventh test
	if ((ret = ft_printf("7. %s is a string\n", "this")) == (tru = printf("7. %s is a string\n", "this")))
	{
		write(1, "***OK***\n", 9);
		ok++;
	}
	else
	{
		nok++;
		printf("yours: %i, true: %i\n", ret, tru);
	}
	//eighth test
	if ((ret = ft_printf("8. Line Feed %s\n", "\n")) == (tru = printf("8. Line Feed %s\n", "\n")))
	{
		write(1, "***OK***\n", 9);
		ok++;
	}
	else
	{
		nok++;
		printf("yours: %i, true: %i\n", ret, tru);
	}

//	ft_printf("9. %10s is a string\n", "this");
//	ft_printf("10. %.2s is a string\n", "this");
//	ft_printf("11. %5.2s is a string\n", "this");
//	ret = ft_printf("12. %10s is a string\n", "");
//	ft_printf("13. %.2s is a string\n", "");
//	ft_printf("14. %5.2s is a string\n", "");
//	ft_printf("15. %-10s is a string\n", "this");
/*	ft_printf("16. %-.2s is a string\n", "this");
	ft_printf("17. %-5.2s is a string\n", "this");
	ft_printf("18. %-10s is a string\n", "");
	ft_printf("19. %-.2s is a string\n", "");
	ft_printf("20. %-5.2s is a string\n", "");
	ft_printf("21. %s %s\n", "this", "is");
	ft_printf("22. %s %s %s\n", "this", "is", "a");
	ft_printf("23. %s %s %s %s\n", "this", "is", "a", "multi");
  	ft_printf("24. %s %s %s %s string. gg!\n", "this", "is", "a", "multi", "string");
	ft_printf("25. %s%s%s%s%s\n", "this", "is", "a", "multi", "string");
	ft_printf("26. @moulitest: %s\n", NULL);*/
}
