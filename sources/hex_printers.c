/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hex_printers.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/09 12:45:43 by mde-cloe      #+#    #+#                 */
/*   Updated: 2022/06/10 21:47:24 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex_convert(unsigned int n, bool is_upper)
{
	char	*lowercase;
	char	*uppercase;

	lowercase = "0123456789abcdef";
	uppercase = "0123456789ABCDEF";
	if (n > 15)
		return (hex_convert(n / 16, is_upper) + hex_convert(n % 16, is_upper));
	if (is_upper)
		return (write(1, &uppercase[n], 1));
	return (write(1, &lowercase[n], 1));
}

int	print_p(va_list *ap)
{
	unsigned int	adress;

	adress = (unsigned int)va_arg(*ap, void *);
	if (!adress)
		return (write(1, "0", 1));
	return (write(1, "0x", 2) + hex_convert(adress, false));
}

int	print_x(va_list *ap)
{
	return (hex_convert(va_arg(*ap, unsigned int), false));
}

int	print_upper_x(va_list *ap)
{
	return (hex_convert(va_arg(*ap, unsigned int), true));
}
