/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchartowstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 14:23:09 by acouturi          #+#    #+#             */
/*   Updated: 2018/01/05 17:14:24 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

wchar_t		*ft_wchartowstr(wint_t c)
{
	wchar_t	*str;

	if (!(str = (wchar_t *)malloc(2 * sizeof(wchar_t))))
		ft_puterror("malloc error");
	str[0] = c;
	str[1] = 0;
	return (str);
}
