/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamp <ehamp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 00:27:38 by elhampto          #+#    #+#             */
/*   Updated: 2019/06/13 20:05:36 by ehamp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclu/ft_printf.h"

static char			*precision_d(int perc, char *point)
{
	int				i;
	char			*res;
	int				j;

	j = perc;
	res = ft_strnew(perc);
	i = ft_strlen(point);
	if (perc < i)
		return (point);
	if (!perc)
		perc = 0;
	while (perc >= 0)
	{
		res[perc] = '0';
		perc--;
	}
	while (i >= 0 && perc)
	{
		res[j] = point[i];
		i--;
		j--;
	}
	return (res);
}

static char			*wzm_help(int wid, char *ans, t_flags *flag, int i)
{
	int				h;

	while (wid > 0 && flag->minus == 0 && flag->width >= 1)
	{
		ans[wid] = ' ';
		wid--;
	}
	flag->width = 0;
	h = -1;
	while (i && flag->minus == 1)
	{
		ans[++h] = ' ';
		i--;
	}
	flag->minus = 0;
	h = ft_strlen(ans) - 1;
	while ((ft_isdigit(ans[h]) == 1 || ans[h] == '-') && flag->zero == 1)
		h--;
	while (ans[h] && flag->zero == 1)
	{
		ans[h] = '0';
		h--;
	}
	flag->zero = 0;
	return (ans);
}

static char			*wid_zer_min_d(int wid, char *s, t_flags *flag)
{
	int				i;
	char			*ans;

	ans = ft_strnew(wid);
	if (flag->minus == 1)
		i = -1;
	else
		i = ft_strlen(s) + 1;
	while (flag->minus == 1 || flag->width >= 1 || flag->zero == 1)
	{
		if (ft_strlen(ans) < ft_strlen(s))
			return (s);
		if (i == -1)
		{
			while (++s[i])
				ans[i] = s[i];
			wid -= i;
		}
		else
			while (s[--i])
			{
				ans[wid] = s[i];
				wid--;
			}
		i = wid;
		ans = wzm_help(wid, ans, flag, i);
	}
	return (ans);
}

static char			*spac_plus_d(char *a, t_flags *flag)
{
	char			*s;
	char			*res;

	s = ft_strnew(ft_strlen(a));
	if (flag->plus == 0)
	{
		*s = '-';
		if (a[0] != '-')
			*s = ' ';
		res = ft_strjoin(s, a);
	}
	else
	{
		a++;
		*s = '+';
		if (flag->sign == 1)
			*s = '-';
		res = ft_strjoin(s, a);
	}
	return (res);
}

void				con_d(va_list options, t_flags *flags, t_val *val)
{
	int64_t			a;
	char			*com;

	a = 0;
	if ((ft_strcmp(flags->length, "l") == 0) ||
		(ft_strcmp(flags->length, "ll") == 0))
		a = va_arg(options, int64_t);
	else
		a = va_arg(options, int32_t);
	com = ft_itoa(a);
	if (flags->precis > 0)
		com = precision_d(flags->precis, com);
	if (flags->width >= 1 || flags->minus == 1 || flags->zero == 1)
		com = wid_zer_min_d(flags->width, com, flags);
	if (flags->space == 1 || flags->plus == 1)
		com = spac_plus_d(com, flags);
	val->k += ft_putstr(com);
}