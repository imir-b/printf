/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbleskin <vbleskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 13:54:19 by vbleskin          #+#    #+#             */
/*   Updated: 2025/11/20 00:15:50 by vbleskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_putstr(char *str);
int	ft_putptr(void *ptr);
int	ft_putnbr(int nbr, char format);
int	ft_putnbrbase(unsigned int nbr, int len, char format);
int	ft_putchar(int i);
int	ft_printf(const char *s, ...);

#endif