/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbleskin <vbleskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 11:59:53 by vbleskin          #+#    #+#             */
/*   Updated: 2025/12/03 12:33:52 by vbleskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi_move(const char **s)
{
	int	nb;

	nb = 0;
	while (**s && ft_isdigit((int)**s))
	{
		nb = nb * 10 + (**s - '0');
		(*s)++;
	}
	return (nb);
}

