/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/07 13:31:38 by mde-cloe      #+#    #+#                 */
/*   Updated: 2022/06/09 18:35:38 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	is_valid_flag(char c)
{
	char	*flags;
	size_t	i;

	flags = "cspdiuxX";
	i = 0;
	while (flags)
	{
		if (c ==flags[i])
			return (1);
		i++;
	}
	return (0);
}

int	flag_checker(char c, va_list *ap)
{
	static int	(*table[128])(va_list *) = \
	{
	['c'] = &print_char, ['s'] = &print_string, ['p'] = print_p, \
	['d'] = &print_nbr, ['i'] = &print_nbr, ['u'] = &print_uns_nbr, \
	['x'] = &print_x, ['X'] = &print_X
	};

	if (!is_valid_flag(c))
		return (0);
	return ((*table[(int)c])(ap));
}

int	ft_printf(const char *str, ...)
{
	int		len;
	size_t	i;
	va_list	ap;

	len = 0;
	i = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '%')
				len += write(1, "%", 1);
			else
				len += flag_checker(str[i], &ap);
		}
		else
			len += write(1, &str[i], 1);
		i++;
	}
	return (len);
}
