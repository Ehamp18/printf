/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:09:30 by elhampto          #+#    #+#             */
/*   Updated: 2019/05/08 14:50:13 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Width
** -- min-width: is the total width, if width is smaller than min width,
** -- its filled with empty spaces: s, c, p, X, x, o, u, d
**
** ** declare the function(with paramitors)
** ** -- check IF width is given or specified
** ** -- -- IF width is speciefed then check if the string or number inputed is greater then
** ** -- -- the number of charaters inputed.
** ** -- -- IF the width is lower then the number of characters, then just print
** ** -- -- the characters.
** 
** Precision
** -- precision: if it is zero or less it is ignored, if it's bigger than the
** -- string it's ignored: s
**
** ** Declare the function(with paramitors)
** ** -- IF the value that is given is 0 or less, then nothing happens
** ** -- IF the value is greater then the string then nothing happens
** ** -- IF the value is above 0 and is lower then the string count, then print
** ** -- - ,characters, up to the number that is specified for the precision.
**
** ||
** -- precision: if precision is smaller than the length of the number it is
** -- ignored, but if it is bigger it is filled with 0's: d, u, o, x, X,
**
** ** -- Declare the function(with paramitors)
** ** -- -- IF precision is smaller then the length, nothing happens.
** ** -- -- IF precision is greater then the length, then 0 are printed for the
** ** -- -- - rest of the spaces given.
**
**  +,  -,  '',  '0'
**
**  d, u, o, x, X:   ll-long long,  l-long,  hh-char,  h-short
**
**  s, p: 2nd flags ignore all
**
**  c: l-'wint_t'
*/