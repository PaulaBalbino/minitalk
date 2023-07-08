/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsignedint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbalbino <pbalbino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 05:52:35 by pbalbino          #+#    #+#             */
/*   Updated: 2023/02/15 09:30:40 by pbalbino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

static void	ft_putunint(unsigned int nb, int *len)
{
	if (nb > 9)
	{
		ft_putunint(nb / 10, len);
		ft_putunint(nb % 10, len);
	}
	else
		ft_putchar('0' + nb, len);
}

void	ft_unsignedint(unsigned int nb, int *output)
{
	ft_putunint(nb, output);
}
