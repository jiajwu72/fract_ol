/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:00:09 by jwu               #+#    #+#             */
/*   Updated: 2018/01/11 20:15:25 by jwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

int				ft_atoi(const char *str);
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *b, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *str, int c, size_t n);
int				ft_memcmp(const void *str1, const void *str2, size_t n);
size_t			ft_strlen(const char *s);
size_t			ft_sstrlen(char **s);
char			*ft_strdup(const char *src);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strncat(char *dest, char *src, unsigned int nb);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *str, int c);
char			*ft_strrchr(const char *str, int c);
char			*ft_strstr(const char *str, const char *to_find);
char			*ft_strnstr(const char *s1, const char *s2, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *str1, const char *str2, size_t n);
int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(int n);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putint(int *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
typedef struct	s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}				t_list;
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
char			*ft_strappend(char *s, char c, size_t i);
char			*ft_strremove(char *s, size_t i);
char			*ft_strreverse(char *s);
t_list			*ft_lstlast(t_list *lst);
size_t			ft_lstlens(t_list *lst);
void			ft_lstclear(t_list **lst);
int				ft_indexof(char *s, char c);
char			*ft_strmerge(char *a, char *b);
char			*ft_firstch(char *buf);
int				ft_endl(char *s);
int				get_next_line(int const fd, char **line);
int				ft_haschar(char *s, char c);
int				ft_isnum(char *s);
int				ft_isint(char *s);
char			*ft_replacechar(char *s, char a, char b);
void			ft_print_tt_char(char **s);
void			ft_print_tt_int(int **s);
int				ft_cnt_parts(const char *s, char c);
int				*ft_intcat(int *dest, const int src);
int				ft_hexa_to_int(char *s);
size_t			ft_intlen(int *s);
int				ft_isnbr(char *s);
int				ft_puiss(int a, int n);
char			*ft_int_to_hexa(int nb);
size_t			ft_tt_intlen(int **s);
int				**ft_tt_intnew(int len, int w);
char			**ft_sstrnew(int len, int w);
int				*ft_intcpy(int *dest, const int *src);
void			ft_free_sstr(char ***s);
void			ft_free_iint(int ***s);
char			*ft_one_str(char *s);
size_t			ft_iintlen(int **s);
char			**ft_sstrcpy(char **dest, char **src);
int				*ft_intnew(int len);
void			ft_print_t_int(int *s);
#endif
