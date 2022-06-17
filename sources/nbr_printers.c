/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   nbr_printers.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/09 13:11:38 by mde-cloe      #+#    #+#                 */
/*   Updated: 2022/06/17 21:33:32 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_nbr(va_list *ap)
{
	char	*nstr;
	size_t	len;

	nstr = ft_itoa(va_arg(*ap, int));
	len = ft_strlen(nstr);
	write(1, nstr, len);
	free(nstr);
	return (len);
}

int	print_uint_rec(unsigned int nbr)
{
	if (nbr > 9)
		return (print_uint_rec(nbr / 10) + print_uint_rec(nbr % 10));
	return();
}
//write with &nbr doesnt work cause it needs the = '0' but you cant do adress plus zero so either add the =0 on a different line
//or use a different sulation like a little uitoa
int	print_uns_nbr(va_list *ap)
{
	unsigned int	nbr;

	nbr = va_arg(*ap, unsigned int);
	return (print_uint_rec(nbr));
}
