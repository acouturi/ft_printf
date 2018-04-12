/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoabaselen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 16:33:19 by acouturi          #+#    #+#             */
/*   Updated: 2018/01/16 15:27:40 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_lennbr(uintmax_t nbr, int base)
{
	int		i;

	i = 0;
	if (!nbr)
		return (1);
	while (nbr > 0)
	{
		nbr /= base;
		i++;
	}
	return (i);
}

char		*ft_utoabaselen(uintmax_t nbr, int base, int mod, int min)
{
	char	*str;
	int		len;
	char	*valbase;

	len = ft_max(ft_lennbr(nbr, base), (uintmax_t)min);
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	valbase = mod == 0 ? "0123456789abcdef" : "0123456789ABCDEF";
	str[len--] = 0;
	if (!nbr)
		str[0] = '0';
	while (len >= 0)
	{
		str[len--] = valbase[nbr % base];
		nbr /= base;
	}
	return (str);
}
