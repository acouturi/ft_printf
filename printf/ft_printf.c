/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 16:15:21 by acouturi          #+#    #+#             */
/*   Updated: 2018/01/16 14:06:14 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>

static void	ft_affichestr(t_remp *stru)
{
	int len;

	len = stru->avecprec == 1 ? ft_min(stru->prec, stru->lenstr) :
		stru->lenstr;
	if (ft_strchrc("sS", stru->type))
		stru->lenstr = len;
	else
		len = ft_wstrlen(stru->str);
	if (ft_strchrc("cC", stru->type) && (char)stru->str[0] == 0)
		ft_putchar(0);
	else if ((stru->type == 'C' || stru->type == 'S'))
		ft_putnwstr(stru->str, len);
	else
		ft_putnstr((char *)stru->str, len);
}

static void	ft_affichemsg(t_remp *stru)
{
	int i;

	if (stru->error != 0)
		return ;
	i = 0;
	ft_lensigne(stru);
	if (stru->avecprec == 1 && stru->remp == '0' && stru->prec < stru->taille &&
			ft_strchrc("diouDOUxXp", stru->type) != 0)
		stru->remp = ' ';
	if (stru->droit == 0 && stru->remp == ' ')
		i = ft_fill(stru, ' ', i);
	ft_affichesigne(stru);
	if (stru->droit == 0 && stru->remp == '0')
		i = ft_fill(stru, '0', i);
	if (ft_strchrc("sScC", stru->type))
		ft_affichestr(stru);
	else
		ft_putstr((char *)stru->str);
	if (stru->droit == 1)
		i = ft_fill(stru, ' ', i);
	stru->len += stru->lenstr + i;
}

static void	ft_gestion(t_remp *stru)
{
	while (ft_strchrc("+# -*", *stru->format) || ft_isdigit(*stru->format))
	{
		if (ft_strchrc("+# ", *stru->format))
			ft_addsigne(stru);
		if (*stru->format == '-' || ft_isdigit(*stru->format) ||
				*stru->format == '*')
			ft_addchamp(stru);
	}
	if (*stru->format == '.')
		ft_addprec(stru);
	if (ft_strchrc("lhjz", *stru->format))
		ft_liretype(stru);
	stru->format -= !stru->format ? 1 : 0;
	if (!(stru->type = ft_strchrc("sScCdiouDOUxX%p", *stru->format)))
	{
		if (!*stru->format)
			return ;
		stru->alloc = 1;
		if ((stru->str = (wchar_t *)ft_chartostr(*stru->format)) == 0)
			stru->error -= 1;
		stru->lenstr = 1;
	}
	stru->format++;
	ft_conv(stru);
	ft_affichemsg(stru);
}

static void	ft_initstr(t_remp *stru)
{
	if (stru->alloc == 1)
		free(stru->str);
	stru->str = NULL;
	stru->alloc = 0;
	stru->longueur = none;
	stru->neg = 0;
	stru->type = 0;
	stru->lenstr = 0;
	stru->signe = 0;
	stru->taille = 0;
	stru->droit = 0;
	stru->prec = 0;
	stru->avecprec = 0;
	stru->remp = ' ';
}

int			ft_printf(const char *format, ...)
{
	char	*start;
	t_remp	remp;

	if (format[0] == '\0')
		return (0);
	ft_bzero(&remp, sizeof(t_remp));
	remp.remp = ' ';
	va_start(remp.ap, format);
	if ((start = ft_strdup(format)) == 0)
		remp.error -= 1;
	else
		remp.format = start;
	while (*remp.format && remp.error == 0)
	{
		while (*remp.format != '%' && *remp.format && (remp.len += 1))
			ft_putchar(*remp.format++);
		ft_initstr(&remp);
		if (*remp.format == '%' && (remp.format += 1))
			ft_gestion(&remp);
	}
	if (remp.alloc == 1)
		free(remp.str);
	free(start);
	va_end(remp.ap);
	return (remp.error == 0 ? remp.len : -1);
}
