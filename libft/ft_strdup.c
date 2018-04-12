/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 21:17:32 by acouturi          #+#    #+#             */
/*   Updated: 2018/01/10 17:41:50 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	int		len;
	char	*news;
	int		i;

	len = ft_strlen(s);
	news = (char*)malloc((len + 1) * sizeof(char));
	if (news == 0)
		return (0);
	i = 0;
	while (s && s[i])
	{
		news[i] = s[i];
		i++;
	}
	news[i] = 0;
	return (news);
}
