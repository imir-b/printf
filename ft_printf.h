/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbleskin <vbleskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 13:54:19 by vbleskin          #+#    #+#             */
/*   Updated: 2025/12/03 10:32:10 by vbleskin         ###   ########.fr       */
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
}	t_struct;

//WRITE UTILS
int			ft_putstr(char *str, t_struct *list);
int			ft_putptr(void *ptr, t_struct *list);
int			ft_putnbr(int nbr, t_struct *list);
int			ft_putnbrbase(unsigned long long nbr, char *base, t_struct *list);
int			ft_putchar(int i, t_struct *list);
//UTILS
int			ft_strlen(const char *str);
const char	*ft_strchr(const char *str, char c);
t_struct	*ft_init_list(void);
//PARSING
int			ft_parsing(const char *s, va_list args, t_struct *list);
//PRINTF
int			ft_printf(const char *s, ...);

#endif