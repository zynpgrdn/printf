/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeogrede <zeogrede@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 12:30:28 by zeogrede          #+#    #+#             */
/*   Updated: 2026/09/21 19:34:25 by zeogrede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int print_hex(long n, char format_chr)
{
	char *hex_array;
	int len;
	char res_chr;
	int res;
	
	len = 0;
	if (format_chr == 'x')
		hex_array = "0123456789abcdef";
	else if (format_chr == 'X')
		hex_array = "0123456789ABCDEF";
	if (n > 15)
	{
		len += print_hex(n / 16, format_chr);
	}
	res = hex_array[n % 16];
	res_chr = res;
	write(1, &res_chr, 1);
	len++;
	return (len);
	
}
static int print_nbr(long n)
{
	int res;
	char res_chr;
	int len;
	
	res = 0;
	len = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		len++;
	}
	if (n > 9)
	{
		len += print_nbr(n / 10);
	}
	res = (n % 10) + '0';
	res_chr = res;
	write(1, &res_chr, 1);
	len++;
	return (len);
}

int ft_printf(const char *format, ...)
{
	int i;
	int len;
	char c;
	int input;
	unsigned int u_input;
	char *temp;
	void *ptr;

	i = 0;
	len = 0;
	va_list args;
	va_start(args, format);
	while (format[i])
	{
		// %% 
		if (format[i] == '%' && format[i + 1] == '%')
		{
			write(1, &format[i], 1);
			len++;
			i += 2;
		}
		//%c
		else if (format[i] == '%' && format[i + 1] == 'c')
		{
			ft_printf_c(args);
			i += 2;
		}
		//%s
		else if (format[i] == '%' && format[i + 1] == 's')
		{
			temp = va_arg(args, char *);
			while (*temp)
			{
				write(1, temp, 1);
				len++;
				temp++;
			}
			i += 2;
		}
		//%d, %i
		else if (format[i] == '%' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
		{
			input = va_arg(args, int);
			len += print_nbr(input);
			i += 2;
		}
		//%u
		else if (format[i] == '%' && format[i + 1] == 'u')
		{
			u_input = va_arg(args, unsigned int);
			len += print_nbr(u_input);
			i += 2;
		}
		//%x %X
		else if (format[i] == '%' && (format[i + 1] == 'X' || format[i + 1] == 'x'))
		{
			u_input = va_arg(args, unsigned int);
			len += print_hex(u_input, format[i + 1]);
			i += 2;
		}
		else if (format[i] == '%' && format[i + 1] == 'p')
		{
			ptr = va_arg(args, void *);
			write (1, "0x", 2);
			len += 2;
			len += print_hex((long)ptr, 'x');
			i += 2;
		}
		else
		
		{
			write(1, &format[i], 1);
			i++;
			len++;
		}
	}
	va_end(args);
	return (len);
}