/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lowerhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbalbino <pbalbino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 06:33:02 by pbalbino          #+#    #+#             */
/*   Updated: 2023/02/15 09:19:58 by pbalbino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_lowerhexa(unsigned int nb, int *output)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (nb >= 16)
		ft_lowerhexa(nb / 16, output);
	write (1, &hex[nb % 16], 1);
	*output = *output +1;
}
