/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 20:00:38 by acouturi          #+#    #+#             */
/*   Updated: 2018/01/15 22:32:05 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

void	ft_addchamp(t_remp *stru)
{
	intmax_t	i;

	if (*stru->format == '-' && (stru->droit = 1))
		stru->format++;
	else if (*stru->format == '0')
	{
		stru->remp = '0';
		stru->format++;
	}
	while (ft_isdigit(*stru->format) || *stru->format == '*')
	{
		stru->taille = 0;
		while (ft_isdigit(*stru->format))
			stru->taille = stru->taille * 10 + *stru->format++ - '0';
		if (*stru->format == '*')
		{
			i = va_arg(stru->ap, intmax_t);
			if ((int)i < 0 && (stru->droit = 1) + 1)
				i = -i;
			stru->taille = i == 0 ? 0 : (unsigned int)i;
			stru->format++;
		}
	}
}

void	ft_addprec(t_remp *stru)
{
	intmax_t	i;

	i = 0;
	stru->format++;
	stru->prec = 0;
	stru->avecprec = 1;
	while (ft_isdigit(*stru->format) || *stru->format == '*')
	{
		stru->prec = 0;
		stru->avecprec = 1;
		while (ft_isdigit(*stru->format))
			stru->prec = stru->prec * 10 + *stru->format++ - '0';
		if (*stru->format == '*')
		{
			i = va_arg(stru->ap, intmax_t);
			stru->prec = (int)i <= 0 ? 0 : (unsigned int)i;
			stru->avecprec = (int)i < 0 ? 0 : 1;
			stru->format++;
		}
	}
}
