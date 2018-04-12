/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lirestr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:13:41 by acouturi          #+#    #+#             */
/*   Updated: 2018/01/17 21:46:24 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

static void		ft_purstrsuite(t_remp *stru)
{
	if (stru->type == 'c' || stru->type == 'C')
	{
		stru->alloc = 1;
		if (stru->type == 'C' || ((stru->type == 'c' && stru->longueur == l) &&
				(stru->type = 'C')))
			stru->str = ft_wchartowstr(va_arg(stru->ap, wint_t));
		else
			stru->str = ft_wchartowstr((wint_t)va_arg(stru->ap, int));
		if (!stru->str)
			stru->error -= 1;
		if (((char)stru->str[0]) == 0)
		{
			free(stru->str);
			if (!(stru->str = ft_wchartowstr(0)))
				stru->error -= 1;
		}
		stru->lenstr = stru->type != 'C' ? 1 : ft_max(ft_wstrlen(stru->str), 1);
	}
}

void			ft_pourstr(t_remp *stru)
{
	if (stru->type == 's' && stru->longueur != l)
	{
		stru->str = (wchar_t *)va_arg(stru->ap, char *);
		stru->str = stru->str ? stru->str : (wchar_t *)"(null)";
		stru->lenstr = ft_strlen((char *)stru->str);
	}
	else if (stru->type == 'S' || (stru->type == 's' && stru->longueur == l))
	{
		stru->type = 'S';
		stru->str = va_arg(stru->ap, wchar_t *);
		stru->str = stru->str ? stru->str : L"(null)";
		stru->lenstr = ft_wstrnlen(stru->str, stru->prec, stru->avecprec);
	}
	else
		ft_purstrsuite(stru);
}
