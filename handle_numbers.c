/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbleskin <vbleskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 01:41:21 by vlad              #+#    #+#             */
/*   Updated: 2025/12/07 18:34:09 by vbleskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_sign(int *nb, int *len, t_struct *list)
{
	char	sign;
	int		bytes;

	bytes = 0;
	if (*nb < 0)
	{
		*nb = -(*nb);
		sign = '-';
		(*len)++;
	}
	else if (*nb >= 0 && list->is_plus)
	{
		sign = '+';
		(*len)++;
	}
	else if (*nb >= 0 && list->is_space)
	{
		sign = ' ';
		(*len)++;
	}
	else
		return (0);
	bytes = ft_putchar(sign, list);
	return (bytes);
}

int	ft_handle_int(int nb, t_struct *list)
{
	int		len;
	int		ret_len;
	char	padding;

	if (nb == 0 && list->precision == 0)
		return (0);
	len = ft_nbrlen(nb);
	ret_len = 0;
	padding = ' ';
	if (list->is_zero && list->precision < 0 && !list->is_minus)
		padding = '0';
	if (!list->is_minus)
		ret_len += ft_put_padding(list->width, len, padding, list);
	ret_len += ft_put_sign(&nb, &len, list);
	while (len < list->precision)
	{
		ret_len += ft_putchar('0', list);
		len++;
	}
	ret_len += ft_putnbr(nb, list);
	if (list->is_minus)
		ret_len += ft_put_padding(list->width, len, padding, list);
	return (ret_len);
}

int	ft_handle_nbrbase(unsigned int nb, const char *base, t_struct *list)
{
	int	len;
	int	ret_len;

	len = ft_nbaselen((unsigned long long)nb, ft_strlen(base));
	if (list->is_minus)
		list->is_zero = 0;
	if (list->is_hash && nb != 0)
		len += 2;
	ret_len = 0;
	if (!list->is_minus && !list->is_zero)
		ret_len += ft_put_padding(list->width, len, ' ', list);
	if (list->is_hash && nb != 0)
	{
		if (ft_isupper(base))
			ret_len += ft_putstr("0X", 2, list);
		else
			ret_len += ft_putstr("0x", 2, list);
	}
	if (!list->is_minus && list->is_zero)
		ret_len += ft_put_padding(list->width, len, '0', list);
	ret_len += ft_putnbrbase((unsigned long long)nb, base, list);
	if (list->is_minus)
		ret_len += ft_put_padding(list->width, len, ' ', list);
	return (ret_len);
}
