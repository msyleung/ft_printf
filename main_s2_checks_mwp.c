/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_spmw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 15:21:02 by sleung            #+#    #+#             */
/*   Updated: 2017/02/20 15:33:25 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	ret = 0;
	int tru = 0;
//9
	if ((ret = ft_printf("9. %10s is a string\n", "this")) == (tru = printf("9. %10s is a string\n", "this")))
		write(1, "***OK***\n", 9);
	else
		printf("yourd: %i, true: %i\n", ret, tru);
//10
	if ((ret = ft_printf("10. %.2s is a string\n", "this")) == (tru = printf("10. %.2s is a string\n", "this")))
		write(1, "***OK***\n", 9);
	else
		printf("yourd: %i, true: %i\n", ret, tru);
//11
	if ((ret = ft_printf("11. %5.2s is a string\n", "this")) == (tru = printf("11. %5.2s is a string\n", "this")))
		write(1, "***OK***\n", 9);
	else
		printf("yourd: %i, true: %i\n", ret, tru);
//12
	if ((ret = ft_printf("12. %10s is a string\n", "")) == (tru = printf("12. %10s is a string\n", "")))
		write(1, "***OK***\n", 9);
	else
		printf("yourd: %i, true: %i\n", ret, tru);
//13
	if ((ret = ft_printf("13. %.2s is a string\n", "")) == (tru = printf("13. %.2s is a string\n", "")))
		write(1, "***OK***\n", 9);
	else
		printf("yourd: %i, true: %i\n", ret, tru);
//13.5
	if ((ret = ft_printf("13.5 %.4s\n", "42")) == (tru = printf("13.5 %.4s\n", "42")))
		write(1, "***OK***\n", 9);
	else
		printf("yourd: %i, true: %i\n", ret, tru);
//14
	if ((ret = ft_printf("14. %5.2s is a string\n", "")) == (tru = printf("14. %5.2s is a string\n", "")))
		write(1, "***OK***\n", 9);
	else
		printf("yourd: %i, true: %i\n", ret, tru);
//14.1
	if ((ret = ft_printf("14.1 %4.5s is a string\n", "*")) == (tru = printf("14.1 %4.5s is a string\n", "*")))
		write(1, "***OK***\n", 9);
	else
		printf("yourd: %i, true: %i\n", ret, tru);
//14.2
	if ((ret = ft_printf("14.2 %4.s is a string\n", "*")) == (tru = printf("14.2 %4.s is a string\n", "*")))
		write(1, "***OK***\n", 9);
	else
		printf("yourd: %i, true: %i\n", ret, tru);
//15
	if ((ret = ft_printf("15. %-10s is a string\n", "this")) == (tru = printf("15. %-10s is a string\n", "this")))
		write(1, "***OK***\n", 9);
	else
		printf("yourd: %i, true: %i\n", ret, tru);
//16
	if ((ret = ft_printf("16. %-.2s is a string\n", "this")) == (tru = printf("16. %-.2s is a string\n", "this")))
		write(1, "***OK***\n", 9);
	else
		printf("yourd: %i, true: %i\n", ret, tru);
//17
	if ((ret = ft_printf("17. %-5.2s is a string\n", "this")) == (tru = printf("17. %-5.2s is a string\n", "this")))
		write(1, "***OK***\n", 9);
	else
		printf("yourd: %i, true: %i\n", ret, tru);
//18
	if ((ret = ft_printf("18. %-10s is a string\n", "")) == (tru = printf("18. %-10s is a string\n", "")))
		write(1, "***OK***\n", 9);
	else
		printf("yourd: %i, true: %i\n", ret, tru);
//19
	if ((ret = ft_printf("19. %-.2s is a string\n", "")) == (tru = printf("19. %-.2s is a string\n", "")))
		write(1, "***OK***\n", 9);
	else
		printf("yourd: %i, true: %i\n", ret, tru);
//20
	if ((ret = ft_printf("20. %-5.2s is a string\n", "")) == (tru = printf("20. %-5.2s is a string\n", "")))
		write(1, "***OK***\n", 9);
	else
		printf("yourd: %i, true: %i\n", ret, tru);
	
	ft_printf("21. %s %s\n", "this", "is");
	ft_printf("22. %s %s %s\n", "this", "is", "a");
	ft_printf("23. %s %s %s %s\n", "this", "is", "a", "multi");
	ft_printf("24. %s %s %s %s string. gg!\n", "this", "is", "a", "multi", "string");
	ft_printf("25. %s%s%s%s%s\n", "this", "is", "a", "multi", "string");
	ft_printf("26. @moulitest: %s\n", NULL);
}
