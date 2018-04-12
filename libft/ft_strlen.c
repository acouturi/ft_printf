/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:15:22 by acouturi          #+#    #+#             */
/*   Updated: 2018/01/10 17:39:51 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <wchar.h>

size_t	ft_strlen(const char *s)
{
	int		comp;

	comp = 0;
	while (s && s[comp])
		comp++;
	return (comp);
}

size_t	ft_wstrlen(const wchar_t *str)
{
	size_t	i;

	i = 0;
	while (*str)
	{
		if (*str <= 0x7F)
			i++;
		else if (*str <= 0x7FF)
			i += 2;
		else if (*str <= 0xFFFF)
			i += 3;
		else if (*str <= 0x10FFFF)
			i += 4;
		str++;
	}
	return (i);
}

size_t	ft_wstrnlen(const wchar_t *str, uintmax_t len, int withprec)
{
	size_t	i;
	int		lu;

	i = 0;
	lu = 0;
	if (withprec == 0)
		len = -1;
	while (*str && i + lu <= len)
	{
		lu = 0;
		if (*str <= 0x7F)
			lu = 1;
		else if (*str <= 0x7FF)
			lu = 2;
		else if (*str <= 0xFFFF)
			lu = 3;
		else if (*str <= 0x10FFFF)
			lu = 4;
		if (i + lu <= len && (i += lu))
			str++;
	}
	return (i);
}
