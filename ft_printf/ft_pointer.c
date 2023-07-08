/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbalbino <pbalbino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 06:27:10 by pbalbino          #+#    #+#             */
/*   Updated: 2023/02/15 09:22:33 by pbalbino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_ptrhexa(unsigned long long int nb, int *output)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (nb >= 16)
		ft_ptrhexa(nb / 16, output);
	write (1, &hex[nb % 16], 1);
	*output = *output +1;
}

void	ft_pointer(void *ptr, int *output)
{
	write (1, "0x", 2);
		*output = *output +2;
	ft_ptrhexa((unsigned long long int) ptr, output);
}
