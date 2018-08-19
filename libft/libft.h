/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 18:41:03 by mienache          #+#    #+#             */
/*   Updated: 2018/03/12 21:00:05 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define BUFF_SIZE 100

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdarg.h>
# include <stdint.h>
# include <wchar.h>

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isalnum(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_intsize(int n);
void				ft_bzero(void *s, size_t n);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memchr(const void *src, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t len);
void				ft_memdel(void **ap);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memmove(void *dst, const void *src, size_t len);
int					ft_atoi(const char *str);
int					ft_atoi_base(char *nb, int base);
long				ft_atol(char *nb);
long long			ft_atoll(char *nb);
char				*ft_itoa(int n);
char				*ft_itoa_base(unsigned long n, unsigned int b);
char				*ft_ltoa(long nb);
long				ft_nbrlen(long nb, long base);
int					ft_power(int nb, int pow);
long				ft_power_long(long nb, long pow);
int					ft_sqrt(int nb);
int					ull_len(unsigned long long nb);
char				*ull_toa(unsigned long long nb);
void				ft_putchar(char c);
void				ft_pputnbr(int n, char const *p);
void				ft_pputstr(char const *s, char const *p);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_pputendl(char const *s, char const *p);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnstr(char const *s, size_t n);
void				ft_putstr(const char *s);
void				ft_putstr_array(char **array, char sep);
void				ft_putstr_fd(char const *s, int fd);
char				*ft_str_realloc(char *old, size_t size);
char				*ft_str_replace(char *origin, char *rep, char *with);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strchr(const char *s, int c);
int					ft_strcchr_rev(const char *s, int c);
void				ft_srclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strcount(char *str, char to_find);
char				*ft_strcpy(char *dest, const char *src);
void				ft_strdel(char **as);
void				ft_strdel_array(char ***as);
char				*ft_strdup(const char *s1);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoin_array(char **array, char *delimiter);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
void				ft_strclr(char *s);
size_t				ft_strlen(const char *s);
size_t				ft_strlen_char(const char *s, char c);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *dest, const char *src, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dest, const char *src, size_t len);
char				*ft_strndup(const char *s1, size_t n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnew_set(size_t size, char c);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strrchr(const char *s, int c);
char				*ft_strrev(char *str);
char				**ft_strsplit(char const *s, char c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
char				*ft_strjoinreplace(char const *s1, char const *s2);
char				*ft_strjoin3(char *s1, char *s2, char *s3);
void				ft_sstrdel(char **s);
char				**ft_sstrdup(char **src);
int					ft_sstrlen(char **s);
char				**ft_sstrnew(size_t size);
int					ft_strxcchr(const char *s, int c);
int					ft_strcchr(const char *s, int c);
char				*ft_sstrtostr(char **s, char *sep);
char				**ft_sstradd(char **s, char *add);
typedef struct		s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}					t_list;
void				ft_lsiter(t_list *lst, void(*f)(t_list *elem));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd_beginning(t_list **alst, t_list *new);
void				ft_lstadd_end(t_list **alst, t_list *new);
void				ft_lstconcat(t_list *lnk_first_list,
							t_list *head_second_list);
void				ft_lstinsert_after(t_list *target, t_list *new);
void				ft_lstinsert_before(t_list **alst,
							t_list *target, t_list *new);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
typedef struct		s_list_gnl
{
	int					fd;
	char				*temp;
	struct s_list_gnl	*next;
}					t_list_gnl;

int					get_next_line(int const fd, char **line);

#endif
