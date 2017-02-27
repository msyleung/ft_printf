/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 16:12:47 by sleung            #+#    #+#             */
/*   Updated: 2017/02/27 13:21:23 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	ret;
	int tru;

//t
	if ((ret = ft_printf("%ju\n", 4999999999)) == (tru = printf("%ld\n", 4999999999)))
		write(1, "***OK***\n", 9);
	else
		printf("yours: %i, true: %i\n~~~~~~~~~~~~~~~~~~\n", ret, tru);
//y
	if ((ret = ft_printf("%zd\n", 0)) == (tru = printf("%zd\n", 0)))
		write(1, "***OK***\n", 9);
	else
		printf("yours: %i, true: %i\n~~~~~~~~~~~~\n", ret, tru);
//first
//	if ((ret = ft_printf("%jd\n", 0)) == (tru = printf("%jd\n", 0)))
//		write(1, "***OK***\n", 9);
//	else
//		printf("yours: %i, true: %i\n~~~~~~~~~~~~~\n", ret, tru);
//secomd
	if ((ret = ft_printf("%jd\n", LONG_MAX)) == (tru = printf("%jd\n", LONG_MAX)))
		write(1, "***OK***\n", 9);
	else
		printf("yours: %i, true: %i\n~~~~~~~~~~~~~~~~\n", ret, tru);
	//min
/*	if ((ret = ft_printf("%hhd\n", -129)) == (tru = printf("%hhd\n", -129)))
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
	if ((ret = ft_printf("ther : %.x\n", 0)) == (tru = printf("ther : %.x\n", 0)))
		write(1, "***ok***\n", 9);
	else
		printf("yours: %i, true: %i\n~~~~~~~~~~~~~~~~~~~~\n", ret, tru);
//#0
	if ((ret = ft_printf("%#x\n", 0)) == (tru = printf("%#x\n", 0)))
		write(1, "***ok***\n", 9);
	else
		printf("yours: %i, true: %i\n~~~~~~~~~~~~~~~~~~~~\n", ret, tru);
//#8x, 0
	if ((ret = ft_printf("|%#08x|\n", 0)) == (tru = printf("|%#08x|\n", 0)))
		write(1, "***ok***\n", 9);
	else
		printf("yours: %i, true: %i\n~~~~~~~~~~~~~~~~~~~~\n", ret, tru);
//for two
	if ((ret = ft_printf("|%#08x|\n", 42)) == (tru = printf("|%#08x|\n", 42)))
		write(1, "***ok***\n", 9);
	else
		printf("yours: %i, true: %i\n~~~~~~~~~~~~~~~~~~~~\n", ret, tru);
	//#8x, 42
	if ((ret = ft_printf("|%#8x|\n", 42)) == (tru = printf("|%#8x|\n", 42)))
		write(1, "***ok***\n", 9);
	else
		printf("yours: %i, true: %i\n~~~~~~~~~~~~~~~~~~~~\n", ret, tru);
	//#-8x
	if ((ret = ft_printf("|%#-8x|\n", 42)) == (tru = printf("|%#-8x|\n", 42)))
		write(1, "***ok***\n", 9);
	else
		printf("yours: %i, true: %i\n~~~~~~~~~~~~~~~~~~~~\n", ret, tru);
/////////////// o!!
	if ((ret = ft_printf("1. |%#6o|\n", 2500)) == (tru = printf("1. |%#6o|\n", 2500)))
		write(1, "***ok***\n", 9);
	else
		printf("yours: %i, true: %i\n~~~~~~~~~~~~~~~~~~~~\n", ret, tru);
	/////////////// o!!
	if ((ret = ft_printf("2. |%-#6o|\n", 2500)) == (tru = printf("2. |%-#6o|\n", 2500)))
		write(1, "***ok***\n", 9);
	else
		printf("yours: %i, true: %i\n~~~~~~~~~~~~~~~~~~~~\n", ret, tru);
	/////////////// o!!
	if ((ret = ft_printf("3. |%-5.1o|\n", 2500)) == (tru = printf("3. |%-5.1o|\n", 2500)))
		write(1, "***ok***\n", 9);
	else
		printf("yours: %i, true: %i\n~~~~~~~~~~~~~~~~~~~~\n", ret, tru);
	//mouli
	if ((ret = ft_printf("4. test |%#.o|\n", 0)) == (tru = printf("4. test |%#.o|\n", 0)))
		write(1, "***ok***\n", 9);
	else
		printf("yours: %i, true: %i\n~~~~~~~~~~~~~~~~~~~~\n", ret, tru);
	//mouli
	if ((ret = ft_printf("5. mouli |%#.0o|\n", 0)) == (tru = printf("5. mouli |%#.0o|\n", 0)))
		write(1, "***ok***\n", 9);
	else
		printf("yours: %i, true: %i\n~~~~~~~~~~~~~~~~~~~~\n", ret, tru);
	//6
	if ((ret = ft_printf("6. mouli |%-6.10o|\n", 2500)) == (tru = printf("6. mouli |%-6.10o|\n", 2500)))
		write(1, "***ok***\n", 9);
	else
		printf("yours: %i, true: %i\n~~~~~~~~~~~~~~~~~~~~\n", ret, tru);
	//7.
	if ((ret = ft_printf("7. mouli |%-10.5o|\n", 2500)) == (tru = printf("7. mouli |%-10.5o|\n", 2500)))
		write(1, "***ok***\n", 9);
	else
		printf("yours: %i, true: %i\n~~~~~~~~~~~~~~~~~~~~\n", ret, tru);
	//8
	if ((ret = ft_printf("8. mouli |%.o|\n", 0)) == (tru = printf("8. mouli |%.o|\n", 0)))
		write(1, "***ok***\n", 9);
	else
		printf("yours: %i, true: %i\n~~~~~~~~~~~~~~~~~~~~\n", ret, tru);
	//9
	if ((ret = ft_printf("9. mouli |%5.o|\n", 0)) == (tru = printf("9. mouli |%5.o|\n", 0)))
		write(1, "***ok***\n", 9);
	else
		printf("yours: %i, true: %i\n~~~~~~~~~~~~~~~~~~~~\n", ret, tru);
	if ((ret = ft_printf("10. mouli |%#.x|\n", 0)) == (tru = printf("10. mouli |%#.x|\n", 0)))
		write(1, "***ok***\n", 9);
	else
		printf("yours: %i, true: %i\n~~~~~~~~~~~~~~~~~~~~\n", ret, tru);
*/
}
