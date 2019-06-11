/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 09:41:51 by elhampto          #+#    #+#             */
/*   Updated: 2019/06/09 23:42:25 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclu/ft_printf.h"

static void			*set(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*a;

	i = -1;
	a = b;
	while (++i < len)
		a[i] = (unsigned char)c;
	return (b);
}

void				*ft_memalloc(size_t size)
{
	void			*fresh;

	if (!(fresh = malloc(size)))
		return (NULL);
	set(fresh, 0, size);
	return (fresh);
}
