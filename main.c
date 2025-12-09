/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbleskin <vbleskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:18:26 by vbleskin          #+#    #+#             */
/*   Updated: 2025/12/09 13:02:46 by vbleskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char	*str = "c -> %c\ns -> %s\np -> %p\nd -> %d\ni -> %i\nu -> %u\nx -> %x\nX -> %X\n% -> %%\n";
	char	*sent = "Python !!!";
	char	c = 'W';
	long	pt = -42;
	int		len;

    len = ft_printf(NULL);
    ft_printf("%d\n", len);
    len = printf(NULL);
    printf("%d\n", len);
	printf("-------- printf / ft_printf--------\n");
	len = printf(str, c, sent, pt, pt, pt, pt, pt, pt);
	printf("len --> %d\n\n", len);
	len = ft_printf(str, c, sent, pt, pt, pt, pt, pt, pt);
	ft_printf("len --> %d\n\n", len);
	printf("-------- printf / ft_printf (NULL) --------\n");
	len = printf(str, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	printf("len --> %d\n\n", len);
	len = ft_printf(str, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	ft_printf("len --> %d\n\n", len);
	printf("-------- printf / ft_printf (EMPTY) --------\n");
	len = printf(NULL);
	printf("len --> %d\n", len);
	len = ft_printf(NULL);
	ft_printf("len --> %d\n\n", len);
	ft_printf("------- mix test -------\n");
	printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%%%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42,'C', "0", 0, 0 ,0 ,0, 42, 0);
	printf("\n");
	ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%%%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42,'C', "0", 0, 0 ,0 ,0, 42, 0);
}