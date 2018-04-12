/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:32:23 by acouturi          #+#    #+#             */
/*   Updated: 2018/01/16 15:03:44 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
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

size_t			ft_strlen(const char *s);
void			ft_putchar(char c);
void			ft_putstr(const char *s);
void			ft_putendl(const char *s);
void			ft_putnbr(int n);
char			*ft_itoa(int n);
int				ft_atoi(const char *nptr);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_strequ(const char *s1, const char *s2);
int				ft_strnequ(const char *s1, const char *s2, size_t n);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strstr(const char *source, const char *mot);
char			*ft_strnstr(const char *source, const char *mot, size_t n);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
void			ft_strdel(char **as);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(const char *s, int fd);
void			ft_putendl_fd(const char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
char			*ft_strdup(const char *s);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strncat(char *dest, const char *src, size_t n);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
void			*ft_memalloc(size_t size);
void			ft_bzero(void *s, size_t n);
void			*ft_memset (void *s, int c, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
char			*ft_strmap(const char *s, char (*f)(char));
char			*ft_strmapi(const char *s, char(*f)(unsigned int, char));
char			*ft_strsub(const char *s, unsigned int start, size_t len);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strtrim(const char *s);
char			**ft_strsplit(const char *s, char c);

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(const void *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *newele);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

int				ft_isupper(int c);
int				ft_islower(int c);
void			ft_lstaddend(t_list **alst, t_list *newele);
char			*ft_strrev(char *str);
void			ft_puterror(const char *str);
long long		ft_pwd(int i, int n);

void			ft_putnstr(const char *str, int n);
size_t			ft_wstrlen(const wchar_t *s);
size_t			ft_wstrnlen(const wchar_t *str, uintmax_t len, int withprec);
void			ft_putwchar(wchar_t chr);
wchar_t			*ft_wchartowstr(wint_t c);
void			ft_putwstr(const wchar_t *s);
void			ft_putnwstr(const wchar_t *s, size_t n);
char			ft_strchrc(char *str, char c);
char			*ft_utoabase(unsigned long long nbr, int base, int mod);
uintmax_t		ft_max(uintmax_t i, uintmax_t j);
uintmax_t		ft_min(uintmax_t i, uintmax_t j);
size_t			ft_nbrlen(int n);
size_t			ft_nbrlenbase(int n, int base);
char			*ft_utoabaselen(uintmax_t nbr, int base, int mod, int min);
char			*ft_chartostr(char c);
#endif
