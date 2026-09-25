/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeogrede <zeogrede@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 19:26:59 by zeogrede          #+#    #+#             */
/*   Updated: 2026/09/21 19:26:59 by zeogrede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf_s(va_list args)
{
    char *temp;
    int len;

    len = 0;
    temp = va_arg(args, char *);
	while (*temp)
	{
	    write(1, temp, 1);
	    len++;
	    temp++;
	}
    return (len);
}