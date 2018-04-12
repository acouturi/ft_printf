/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnwstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 15:26:39 by acouturi          #+#    #+#             */
/*   Updated: 2018/01/16 15:27:05 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnwstr(const wchar_t *str, size_t len)
{
	size_t	i;
	int		lu;

	i = 0;
	lu = 0;
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
			ft_putwchar(*str++);
	}
}
