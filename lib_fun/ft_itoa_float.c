/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 19:18:36 by elhampto          #+#    #+#             */
/*   Updated: 2019/06/10 19:57:29 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclu/ft_printf.h"

static int				ft_numcount(double *in)
{
	int					j;

	j = 0;
	while (in[j])
		j++;
	return (j);
}

char					*ft_itoa_float(double flo)
{
	double				len;
	char				**test;
	int					i;
	static char			*l = NULL;

	*test = (char*)ft_memalloc(sizeof(ft_numlen(flo)));
	**test = flo;
	i = 0;
	len = ft_numcount(&flo);
	*test = *ft_strsplit(*test, '.');
	return (l);
}
