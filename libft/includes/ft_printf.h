/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etristan <etristan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 21:54:23 by etristan          #+#    #+#             */
/*   Updated: 2020/07/17 23:41:55 by etristan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "s_prft.h"
# include "libft.h"
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include <sys/types.h>
# include <inttypes.h>
# include <limits.h>

# define H				1
# define HH				2
# define L				3
# define LL				4
# define J				5
# define Z				6
# define BIGL			7
# define ALLPREOBR	"cspdiouxXfybnK%"
# define ALLSYM "cspdiouxXfybnK%#-+ .*0123456789hLljz"
# define ALLFLAGS "0+# -"
# define ALLMODIF "hlLjz"
# define LOWER 20
# define UPPER 10
# define POSITIV 66
# define NEGATIV 88

int				ft_printf(const char *format, ...);

int				ft_parsing(const char *format, t_printf *f, va_list ap);
int				ft_parstwo(const char *format, t_printf *f, va_list ap);
void			argsflags(const char *format, t_printf *f, va_list ap);
void			check_modif(const char *format, t_printf *f);
void			check_precision(const char *format, t_printf *f,
		va_list ap, int i);
void			check_width(const char *format, t_printf *f, va_list ap);
void			check_flags(const char *format, t_printf *f);
void			conversions(char c, t_printf *f, va_list ap);

void			print_char(t_printf *f, va_list ap);
void			left_char(t_printf *f, char c);
void			right_char(t_printf *f, char c);
void			charnull(t_printf *f);
void			print_percent(t_printf *f);
void			print_string(t_printf *f, va_list ap);
void			left_string(t_printf *f, char *str, int len);
void			right_string(t_printf *f, char *str, int len);
void			strnull(t_printf *f);

void			print_int(t_printf *f, va_list ap, int znak, intmax_t num);
void			ft_pars_int(t_printf *f, intmax_t num, int znak);
void			ft_left_int(t_printf *f, char *number, int len, int znak);
void			ft_right_int(t_printf *f, char *number, int len, int znak);
void			ft_print_znak(t_printf *f, int znak);

void			print_unsigned(t_printf *f, va_list ap, uintmax_t num);
void			ft_pars_un(t_printf *f, uintmax_t num);
void			ft_left_un(t_printf *f, char *number, int len);
void			ft_right_un(t_printf *f, char *number, int len);

void			print_pointer(t_printf *f, va_list ap);
void			right_pointer(t_printf *f, char *pointer, int len);
void			left_pointer(t_printf *f, char *pointer, int len);

void			print_binary(t_printf *f, va_list ap);
void			parse_binary(t_printf *f, uintmax_t num, char *str);
void			left_binary(t_printf *f, char *number, int len);
void			right_binary(t_printf *f, char *number, int len);
void			print_octal(t_printf *f, va_list ap);
void			parse_octal(t_printf *f, uintmax_t num);
void			left_octal(t_printf *f, char *number, int len);
void			right_octal(t_printf *f, char *number, int len);
void			print_hexa(t_printf *f, va_list ap, char x);
void			parse_hexa(t_printf *f, uintmax_t num, char *str, char x);
void			left_hexa(t_printf *f, char *number, int numlen, char x);
void			right_hexa(t_printf *f, char *number, int numlen, char x);

void			print_float(t_printf *f, va_list ap);
void			parse_float_one(t_printf *f, long double n);
t_float			parse_float_two(t_printf *f, t_float fl, long double n);
t_float			parse_float_three(t_printf *f, t_float fl);
void			left_float(t_printf *f, t_float fl);
void			right_float_beforedot(t_printf *f, t_float fl);
void			right_float_afterdot(t_printf *f, t_float fl);

void			zero_struct(t_printf *list);
void			zero_struct_two(t_printf *list);
char			*ft_itoa_base(uintmax_t value, uintmax_t base, int registr);
int				number_len(intmax_t num, int n);
void			writezeros(int n);
void			writespace(int n);
void			error(void);
long double		power(intmax_t n, int k);
void			numer(t_printf *f, va_list ap);
void			color(t_printf *f, va_list ap);
void			palitra(void);

#endif
