/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlenbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 16:18:48 by acouturi          #+#    #+#             */
/*   Updated: 2018/01/11 16:19:27 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_nbrlenbase(int n, int base)
{
	size_t size;

	size = 0;
	if (n < 0)
		size++;
	while (n / base != 0)
	{
		n /= base;
		size++;
	}
	size++;
	return (size);
}
