/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 14:03:37 by acouturi          #+#    #+#             */
/*   Updated: 2018/01/15 13:27:13 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <stdint.h>
# include <stdarg.h>
# include <errno.h>
# include <assert.h>
# include <wchar.h>
# include <inttypes.h>

typedef struct	s_remp
{
	unsigned long long	len;
	va_list				ap;
	char				*format;
	wchar_t				*str;
	char				type;
	char				neg;
	char				signe;
	long				lenstr;
	enum	{
		none,
		hh,
		h,
		l,
		ll,
		j,
		z
	}					longueur;
	unsigned int		taille;
	int					droit;
	unsigned int		prec;
	char				remp;
	char				avecprec;
	int					alloc;
	int					error;
}				t_remp;

int				ft_printf(const char *format, ...);
void			ft_conv(t_remp *stru);
void			ft_addsigne(t_remp *stru);
void			ft_affichesigne(t_remp *stru);
void			ft_pourstr(t_remp *stru);
void			ft_liretype(t_remp *stru);
void			ft_addchamp(t_remp *stru);
void			ft_addprec(t_remp *stru);
void			ft_lensigne(t_remp *stru);
int				ft_fill(t_remp *stru, char c, int i);

#endif
