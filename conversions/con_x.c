/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 00:28:45 by elhampto          #+#    #+#             */
/*   Updated: 2019/07/17 19:38:59 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclu/ft_printf.h"

static char			*precision_x(int perc, char *point)
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
	free(point);
	return (res);
}

static char			*wzm_help(int wid, char *ans, t_flags *flag, int i)
{
	int				h;
	int				k;

	k = wid;
	while (wid >= 0 && flag->minus == 0 && flag->width >= 1)
	{
		ans[wid] = ' ';
		wid--;
	}
	h = ft_strlen(ans);
	while (i >= 0 && flag->minus == 1)
	{
		ans[h++] = ' ';
		i--;
	}
	while ((ft_isdigit(ans[k]) == 1 || ans[k] == '-') && flag->zero == 1 &&
		flag->precis == 0)
		k--;
	while (ans[k] && flag->zero == 1 && flag->precis == 0)
	{
		ans[k] = '0';
		k--;
	}
	return (ans);
}

static char			*wid_zer_min_x(int wid, char *s, t_flags *flag)
{
	int				i;
	char			*ans;

	ans = ft_strnew(wid);
	i = flag->minus == 1 ? -1 : ft_strlen(s);
	if (wid-- < (int)ft_strlen(s))
		return (s);
	if (i == -1)
	{
		while (s[++i] && s[i])
			ans[i] = s[i];
		wid -= i;
	}
	else
		while (i-- > 0)
		{
			ans[wid] = s[i];
			wid--;
		}
	i = wid;
	ans = wzm_help(wid, ans, flag, i);
	free(s);
	return (ans);
}

static char			*hash_x(char *s)
{
	if ((ft_atoi(s) > 0 || (ft_isalpha(*s) == 1)) && *s != 0)
		s = ft_ccstrjoin('0', 'x', s);
	return (s);
}

void				con_x(va_list options, t_flags *flags, t_val *val)
{
	int64_t			a;
	char			*com;

	a = 0;
	if ((ft_strcmp(flags->length, "l") == 0) ||
		(ft_strcmp(flags->length, "ll") == 0))
		a = va_arg(options, uint64_t);
	else
		a = va_arg(options, uint32_t);
	com = ft_itoa_x(a);
	if (flags->precis > 0 || flags->precis == -1)
		com = precision_x(flags->precis, com);
	if (flags->hash == 1)
		com = hash_x(com);
	if (flags->width >= 1 || flags->minus == 1 || flags->zero == 1)
		com = wid_zer_min_x(flags->width, com, flags);
	val->k += ft_putstr(com);
	free(com);
}
