/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_upperhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbalbino <pbalbino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 06:35:31 by pbalbino          #+#    #+#             */
/*   Updated: 2023/02/15 09:31:58 by pbalbino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_upperhexa(unsigned int nb, int *output)
{
	char	*hex;

	hex = "0123456789ABCDEF";
	if (nb >= 16)
		ft_upperhexa(nb / 16, output);
	write (1, &hex[nb % 16], 1);
	*output = *output +1;
}
