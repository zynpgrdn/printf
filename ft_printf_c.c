/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeogrede <zeogrede@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 19:18:31 by zeogrede          #+#    #+#             */
/*   Updated: 2026/09/21 19:18:31 by zeogrede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf_c(va_list args)
{
    int input;
    char c;
    int len;

    len = 0;
    input = va_arg(args, int);
	c = (char)input;
	write(1, &c, 1);
	len++;
	return (len);
}