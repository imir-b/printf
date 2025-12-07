/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbleskin <vbleskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 13:54:19 by vbleskin          #+#    #+#             */
/*   Updated: 2025/12/07 18:34:35 by vbleskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_struct
{
	int	is_minus;
	int	is_zero;
	int	is_dot;
	int	is_hash;
	int	is_space;
	int	is_plus;
	int	error;
	int	width;
	int	precision;
}	t_struct;

//WRITE UTILS
int			ft_putstr(char *str, int len, t_struct *list);
int			ft_putptr(void *ptr, t_struct *list);
int			ft_putnbr(int nbr, t_struct *list);
int			ft_putnbrbase(unsigned long long nbr, const char *base, \
				t_struct *list);
int			ft_putchar(int i, t_struct *list);
//UTILS
t_struct	*ft_init_list(void);
void		ft_reset_list(t_struct *list);
int			ft_strlen(const char *str);
const char	*ft_strchr(const char *str, char c);
int			ft_nbrlen(int nb);
int			ft_nbaselen(unsigned long long n, int base_len);
int			ft_isdigit(int c);
int			ft_isupper(const char *str);
int			ft_atoi_move(char **s);
//HANDLE FT
int			ft_handle_int(int nb, t_struct *list);
int			ft_handle_char(int c, t_struct *list);
int			ft_handle_str(char *str, t_struct *list);
int			ft_handle_nbrbase(unsigned int n, const char *base, t_struct *list);
int			ft_handle_ptr(void *ptr, t_struct *list);
//PARSING
int			ft_put_padding(int width, int len, char c, t_struct *list);
char		*ft_check_flags(char *s, t_struct *list);
int			ft_parsing(const char *s, va_list args, t_struct *list);
//PRINTF
int			ft_printf(const char *s, ...);

#endif