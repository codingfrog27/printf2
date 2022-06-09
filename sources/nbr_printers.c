/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   nbr_printers.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/09 13:11:38 by mde-cloe      #+#    #+#                 */
/*   Updated: 2022/06/09 19:00:49 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_nbr(va_list *ap)
{
	char	*nstr;
	size_t	len;

	nstr = ft_itoa(va_arg(*ap, int));
	len = ft_strlen(nstr);
	free(nstr);
	return (len);
}

int	print_uint_rec(unsigned int nbr)
{
	if (nbr > 9)
	{
		print_uint_rec(nbr / 10);
		print_uint_rec(nbr % 10);
	}
	return (write(1, &nbr, 1));
}

//check if written bytes are accurate
int	print_uns_nbr(va_list *ap)
{
	unsigned int	nbr;

	nbr = va_arg(*ap, unsigned int);
	return (print_uint_rec(nbr));
}
