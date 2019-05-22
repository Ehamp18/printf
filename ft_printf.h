/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:52:49 by elhampto          #+#    #+#             */
/*   Updated: 2019/05/22 12:08:55 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

# define BREAK(x) if (x) break
# define ZERO(x) if (x) return (0)
# define ERROR(x) if (x) return (-1)

typedef	void	(*t_charat)(va_list conversions);

typedef struct	s_conv_check
{
	char		op;
	t_charat	kl;
}				t_check;

typedef struct	s_flags
{
	int			minus;
	int			plus;
	int			zero;
	int			space;
	int			hash;
}				t_flags;

typedef struct	s_wiprel
{
	int			width;
	int			precis;
	char		*length;
}				t_wiprel;

extern t_check	g_conver_check[];

int				ft_printf(const char *format, ...);
void			con_d(va_list options);
void			con_i(va_list options);
void			con_c(va_list options);
void			con_s(va_list options);
void			con_x(va_list options);
void			con_xa(va_list options);
void			con_p(va_list options);
void			con_o(va_list options);
void			con_u(va_list options);
void			con_f(va_list options);
int				checks(va_list options, const char *format);
char			width(int wid, char *s);
char			minus_flag(char *m);
char			plus_flag(char *a);
char			space_flag(char *a);
char			zero_flag(char *a);
char			l_flag(long k);
char			precision(int perc, char *point);

#endif
