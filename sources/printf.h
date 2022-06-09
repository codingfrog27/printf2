/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/07 13:32:46 by mde-cloe      #+#    #+#                 */
/*   Updated: 2022/06/09 17:57:50 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft.h"
# include <stdbool.h>

int	flag_checker(char c, va_list *ap);
int	print_char(va_list *ap);
int	print_string(va_list *ap);
int	print_p(va_list *ap);
int	print_nbr(va_list *ap);
int	print_uns_nbr(va_list *ap);
int	print_x(va_list *ap);
int	print_X(va_list *ap);

#endif