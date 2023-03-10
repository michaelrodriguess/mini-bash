/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:04:52 by fcaetano          #+#    #+#             */
/*   Updated: 2023/03/09 14:52:09 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# define BUFFER_SIZE 1000

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}					t_list;

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t len);
void	*ft_memset(void *s, int c, size_t n);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_lstdisplay(t_list *lst);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);
int		ft_atoi(const char *str);
int		ft_abs(int n);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_strncmp(const char *s1, const char *s2, unsigned int n);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_toupper(int c);
int		ft_lstsize(t_list *lst);
int		ft_i_strchr(const char *s, int c);
int		ft_printf(const char *str, ...);
int		ftpf_strchr(const char *s, int c);
int		ftpf_putchar(char c);
int		ftpf_putstr(char *s);
int		ftpf_strlen(const char *str);
int		putptr_rec(unsigned long n, char t);
int		putptr(unsigned long n, char t);
int		putdec_rec(int n);
int		ft_ahtoi(char *str);
int		ft_strchri(const char *s, int c);
int		ft_isnum(int c);
int		putdec(int n);
int		putunsigned(unsigned int base, unsigned int n, char c);
int		print_specifiers(va_list ptr, char specifier);
int		ft_tolower(int c);
int		ft_size_matriz(char **matriz);
size_t	ft_strlcat(char *dest, const char *src,	size_t destsize);
size_t	ft_strlcpy(char *dest, const char *src, size_t destsize);
size_t	ft_strlen(const char *str);
size_t	ft_array_len(char **str);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *src);
char	*ft_strnstr(const char *str, const char *to_find, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_read(int fd);
char	*check_bread(char *sbuf, char *line, int nli);
char	*check_EOF(char *sbuf, char *temp);
char	*get_next_line(int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strtrim_free(char const *s1, char const *set, char **addr);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strjoin(char const *s1, char const *s2);
char	*strjoinchr(char *str, char chr);
char	*remove_substr(char	*str, int from, int to);
char	*insert_substr(char	*str, char *substr, int i);
char	**ft_split(char const *s, char c);
char	*ft_strjoin_gnl(char *s1, char *s2);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int content);

#endif
