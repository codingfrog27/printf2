/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/02 15:29:58 by mde-cloe      #+#    #+#                 */
/*   Updated: 2022/06/02 17:40:23 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

int	ft_printf(const char *str, ...);

int	main(void)
{
	char	*str = "hi Im a string";
	//printf("|testing  here \n |->");
	ft_printf("testing char -> %c\n", 'A');
	ft_printf("testing str -> %s\n", str);

	return (0);
}