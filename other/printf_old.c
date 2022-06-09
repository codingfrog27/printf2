/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_old.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/02 15:28:33 by mde-cloe      #+#    #+#                 */
/*   Updated: 2022/06/09 12:54:48 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdarg.h>
#include <unistd.h>

int	ft_printf(const char *str, ...)
{
	size_t	len;
	va_list	ap;
	size_t	i;

	len = 0;
	va_start(ap, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 'c')
			{
				char c = va_arg(ap, int);
				len += write(1, &c, 1);
			}
			else if (str[i == 's'])
			{
				char	*str2 = va_arg(ap, char *);
				size_t	j = 0;
				if (!str2)
					len += write(1, "(null)", 6);
				while (str2[j])
				{
					len += write(1, &str2[j], 1);
					j++;
				}
			}
			else if (str[i] == 'p')
			{
				unsigned long adress = va_arg(ap, unsigned long);
				len += write(1, "0x", 2);
			}
			i++;
		}
		len += write(1, &str[i], 1);
		i++;
    }
	va_end(ap);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	size_t	len;
	va_list	ap;
	size_t	i;

	len = 0;
	va_start(ap, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '%')
		}
		len += write(1, &str[i], 1);
		i++;
    }
	va_end(ap);
	return (len);
}


static int	(*table[128])(va_list *) = \
	{
	['c'] = &print_char, ['s'] = &print_string, ['p'] = print_p, \
	['d'] = &print_d, ['i'] = &print_i, ['u'] = &print_u, \
	['x'] = &print_x, ['X'] = &print_X
	};