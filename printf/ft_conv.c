/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:31:38 by acouturi          #+#    #+#             */
/*   Updated: 2018/01/15 20:57:39 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

static uintmax_t	ft_castu(t_remp *stru, uintmax_t d)
{
	if (stru->longueur == none)
		d = (unsigned int)d;
	if (stru->longueur == hh)
		d = (unsigned char)d;
	if (stru->longueur == h)
		d = (unsigned short)d;
	if (stru->longueur == l)
		d = (unsigned long)d;
	if (stru->longueur == ll)
		d = (unsigned long long)d;
	if (stru->longueur == j)
		d = (uintmax_t)d;
	if (stru->longueur == z)
		d = (size_t)d;
	return (d);
}

static intmax_t		ft_casti(t_remp *stru, intmax_t d)
{
	if (stru->longueur == none)
		d = (int)d;
	if (stru->longueur == hh)
		d = (char)d;
	if (stru->longueur == h)
		d = (short)d;
	if (stru->longueur == l)
		d = (long)d;
	if (stru->longueur == ll)
		d = (long long)d;
	if (stru->longueur == j)
		d = (intmax_t)d;
	if (stru->longueur == z)
		d = (size_t)d;
	return (d);
}

static void			ft_pournbrsuite(t_remp *stru, uintmax_t d)
{
	int		base;

	base = stru->type == 'o' || stru->type == 'O' ? 8 : 0;
	if (!base)
		base = ft_strchrc("xXp", stru->type) ? 16 : 10;
	if (stru->avecprec == 1 && stru->prec == 0 && d == 0)
		stru->str = (wchar_t *)ft_strdup(NULL);
	else
	{
		stru->str = (wchar_t *)ft_utoabaselen(d, base, stru->type == 'X' ?
			1 : 0, stru->prec);
		if (stru->str == 0 && (stru->error -= 1) - 1 == 0)
			return ;
		stru->alloc = 1;
	}
	stru->lenstr = ft_strlen((char *)stru->str);
}

static void			ft_pournbr(t_remp *stru)
{
	intmax_t		i;
	uintmax_t		d;

	if (ft_tolower(stru->type) == 'o' && stru->signe == '#' && stru->prec > 1)
		stru->prec--;
	if (stru->type == 'p' && (stru->longueur = l))
		stru->signe = '#';
	if (ft_strchrc("diD", stru->type))
	{
		if ((i = ft_casti(stru, va_arg(stru->ap, intmax_t))) < 0)
		{
			stru->neg = '-';
			d = (uintmax_t)(-(++i)) + 1;
		}
		else
			d = i;
	}
	else
		d = ft_castu(stru, va_arg(stru->ap, uintmax_t));
	ft_pournbrsuite(stru, d);
}

void				ft_conv(t_remp *stru)
{
	if (ft_strchrc("sScC", stru->type))
		ft_pourstr(stru);
	else if (ft_strchrc("pdiouDOUxX", stru->type))
	{
		if (ft_strchrc("DOU", stru->type))
			stru->longueur = l;
		ft_pournbr(stru);
	}
	else if (stru->type == '%')
	{
		stru->str = L"%";
		stru->lenstr = 1;
	}
}
