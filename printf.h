/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbleskin <vbleskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 13:54:19 by vbleskin          #+#    #+#             */
/*   Updated: 2025/12/02 14:11:42 by vbleskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stddef.h>
# include <stdarg.h>

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
int		ft_putstr(char *str, t_struct *list);
int		ft_putptr(void *ptr, t_struct *list);
int		ft_putnbr(int nbr, t_struct *list);
int		ft_putnbrbase(unsigned long long nbr, int bytes, char *base, \
			t_struct *list);
int		ft_putchar(int i, t_struct *list);
//UTILS
int		ft_strlen(const char *str);
char	*ft_strchr(char *str, char c);
//PRINTF
int		ft_printf(const char *s, ...);

#endif