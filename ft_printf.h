/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 15:46:04 by sleung            #+#    #+#             */
/*   Updated: 2017/02/23 13:19:13 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define INT_MAX 2147483647
# define UINT_MAX 4294967295

typedef struct	s_struct
{
	char	*fo;
	char	*st;
	int		i;
	int		flag;
	int		sharp;
	char	conv;
	int		zero;
	int		minus;
	int		plus;
	int		space;
	int		mw;
	int		p;
	char	lm;
}				t_struct;

int				ft_printf(const char *format, ...);
int				ft_printf_c(int c, t_struct *d);
int				ft_printf_s(char *str, t_struct *d);
int				ft_printf_i(int n, t_struct *d);
int				ft_printf_x(int n, t_struct *d);
int				ft_printf_cx(int n, t_struct *d);
int				ft_printf_o(int n, t_struct *d);
int				ft_printf_co(long n, t_struct *d);
int				ft_printf_pt(t_struct *d);
int				ft_printf_u(unsigned int n, t_struct *d);
int				ft_printf_cu(unsigned long n, t_struct *d);
int				ft_printf_p(void *ptr, t_struct *d);
int				get_size(t_struct *d);
void			check_flags(t_struct *d);
int				check_conv(t_struct *d);
int				read_data(va_list ap, t_struct *d);
void			handle_sign(t_struct *d, char **tmp, char **str, int *ti);
void			handle_flags(t_struct *d, int *space, int *zero, int n);
void			handle_sharp(t_struct *d, char **tmp, int *ti, int n);
int				count_spaces(t_struct *d, int len);
int				count_zeros(t_struct *d, int len, int n);
int				count_spaces_int(t_struct *d, int len, int n);
int				write_spaces(int spaces, char *tmp, int ti);
int				write_zeros(int zeros, char *tmp, int ti);
char			*ft_itoa_base(unsigned int value, int base);
char			*ft_itoa_unsigned(unsigned int value);
int				ft_atoi(const char *str);
void			*ft_memset(void *b, int c, size_t len);
void			ft_strdel(char **as);
char			*ft_strnew(size_t size);
size_t			ft_strlen(const char *s);
int				ft_intlen(int nb);
char			*ft_strjoin(char const *s1, char const *s2);
int				ft_putstr(char *tmp);
int				ft_putstrdel(char **as, int ti);

#endif
