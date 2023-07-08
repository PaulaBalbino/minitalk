/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbalbino <pbalbino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 05:07:13 by pbalbino          #+#    #+#             */
/*   Updated: 2023/02/15 09:19:27 by pbalbino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr(int nb, int *len);

static void	ft_putchar(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

static void	ft_putnbr(int nb, int *len)
{
	if (nb == -2147483648)
	{
		ft_putchar('-', len);
		ft_putchar('2', len);
		ft_putnbr(147483648, len);
	}
	else if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-', len);
		ft_putnbr(nb, len);
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10, len);
		ft_putnbr(nb % 10, len);
	}
	else
		ft_putchar('0' + nb, len);
}

void	ft_digit(int i, int *output)
{
	ft_putnbr(i, output);
}
