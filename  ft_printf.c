/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    ft_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeogrede <zeogrede@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 12:30:28 by zeogrede          #+#    #+#             */
/*   Updated: 2026/09/15 16:20:48 by zeogrede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	int i;

	i = 0;
	va_list args;
	va_start(args,format);
	while(*format)
	{
		write(1, &format[i],1);
		i++;
		return (i);
	}
	va_end(args);
	return (0);
}