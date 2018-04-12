/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addsigne.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 19:02:46 by acouturi          #+#    #+#             */
/*   Updated: 2018/01/15 21:11:09 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

int		ft_fill(t_remp *stru, char c, int i)
{
	if (stru->avecprec == 1 && ft_strchrc("sS", stru->type))
		while (stru->taille > ft_min(stru->lenstr, stru->prec) + i && ++i)
			ft_putchar(c);
	else
		while (stru->taille > stru->lenstr + i && ++i)
			ft_putchar(c);
	return (i);
}

void	ft_addsigne(t_remp *stru)
{
	while (ft_strchrc("+# ", *stru->format))
	{
		if (*stru->format == '#')
			stru->signe = *stru->format;
		else if (*stru->format == '+' && stru->signe != '#')
			stru->signe = *stru->format;
		else if (*stru->format == ' ' && !stru->signe)
			stru->signe = *stru->format;
		stru->format++;
	}
}

void	ft_lensigne(t_remp *stru)
{
	if ((ft_strcmp((char *)stru->str, "0") == 0 && stru->signe != '+' &&
			stru->signe != ' ' && stru->type != 'p') ||
			ft_strchrc("scSC", stru->type) != 0)
		return ;
	stru->lenstr++;
	if (stru->neg)
		return ;
	if (stru->signe == ' ' || stru->signe == '+')
	{
		if (ft_strchrc("dDi", stru->type))
			return ;
		stru->lenstr--;
		return ;
	}
	if (stru->signe == '#' && (stru->str[0] != '\0' || ft_tolower(stru->type)
				== 'o' || stru->type == 'p'))
	{
		if (stru->type == 'x' || stru->type == 'X' || stru->type == 'p')
			stru->lenstr++;
		return ;
	}
	stru->lenstr--;
}

void	ft_affichesigne(t_remp *stru)
{
	if ((ft_strcmp((char *)stru->str, "0") == 0 && stru->signe != '+' &&
			stru->signe != ' ' && stru->type != 'p') ||
			ft_strchrc("scSC", stru->type) != 0)
		return ;
	if (stru->neg)
		return (ft_putchar('-'));
	if (stru->signe == ' ' || stru->signe == '+')
	{
		if (ft_strchrc("dDi", stru->type))
			return (ft_putchar(stru->signe));
		return ;
	}
	if (stru->signe == '#' && ft_tolower(stru->type) == 'o')
		return (ft_putchar('0'));
	if ((stru->signe == '#' && (stru->type == 'x' || stru->type == 'X') &&
				stru->str[0] != '\0') || stru->type == 'p')
	{
		ft_putchar('0');
		return (ft_putchar(stru->type == 'X' ? 'X' : 'x'));
	}
}
