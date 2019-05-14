/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <oel-ayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:12:24 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/05/14 07:45:02 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_memdel(void **ap);
void				ft_strdel(char **as);
void				ft_putchar(char c);
void				ft_putstr(const char *s);
void				ft_putendl(const char *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_bzero(void *s, size_t n);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elmt));
void				ft_lst_pushback(t_list **beginlst, t_list *lst);
void				ft_sort_intger_table(int *tab, int size);
void				ft_swap(int *a, int *b);
void				ft_del_tab(char ***tab);

void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memcpy(void *restrict dst, const void *restrict src,
size_t n);

char				*ft_strnew(size_t size);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char(*f)(unsigned int, char));
char				*ft_strsub(char const *s, size_t start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoin_free(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				*ft_itoa(int nb);
char				*ft_itoa_base(long long nb, int base);
char				*ft_strdup(const char *src);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, int nb);
char				*ft_strchr(char *str, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *str, const char *to_find);
char				*ft_strnstr(const char *str, const char *tofind, size_t n);
char				*ft_strtolower(char *str);
char				*ft_strntolower(char *str, size_t n);
char				*ft_strupcase(char *str);
char				*ft_strcapitalize(char *str);
char				*ft_strlowcase(char *str);
char				*ft_strnlowcase(char *str, size_t n);
char				*ft_strndup(const char *str, size_t size);
char				*ft_strrev(char *str);
char 				*ft_str_from_char(char c);
char				*ft_ftoa(double f, size_t precision);
char				*utoa_base(unsigned long long n, int b);
char        		*ft_strjoin_char(char c, char *s1, int opt);

char				**ft_strsplit(char const *s, char c);
char				**ft_strsplit(char const *s, char c);
char				**ft_split_whitespaces(char *str);

int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_isalnum(int c);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_atoi(const char *str);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_strncmp(const char *str1, const char *str2, size_t n);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_isblank(int c);
int					ft_iscntrl(char c);
int					ft_isgraph(char c);
int					ft_islower(int c);
int					ft_isspace(char c);
int					ft_isupper(int c);
int					ft_isxdigit(char c);
int					ft_str_is_alpha(const char *str);
int					ft_str_is_lowercase(const char *str);
int					ft_str_is_numeric(const char *str);
int					ft_str_is_printable(const char *str);
int					ft_str_is_uppercase(const char *str);
int					ft_strncasecmp(const char *s1, const char *s2, size_t n);
int					ft_strcasecmp(const char *s1, const char *s2);
int					ft_lstsize(t_list *begin_list);
int					get_size_nb(int nb);
int					supdigit_at(int nb, int rank);
int					ft_supzero(int nb);
int					get_digit_at(int nb, int rank);
int					ft_supdigit(int nb, int size);


size_t				ft_strlen(const char *str);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_tab_len(char **str);

t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstget_at(t_list *begin_list, size_t nbr);
t_list				*ft_lstfind(t_list *begin_list, void *data);

long long	ft_pow(int nb, int power);

#endif
