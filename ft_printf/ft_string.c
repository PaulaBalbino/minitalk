/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbalbino <pbalbino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 05:38:14 by pbalbino          #+#    #+#             */
/*   Updated: 2023/02/15 08:53:30 by pbalbino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_string(char *str, int *len)
{
	int	i;

	i = 0;
	if (str == 0)
	{
		write (1, "(null)", 6);
		*len = *len + 6;
		return ;
	}
	while (str[i] != 0)
	{
		write (1, &str[i], 1);
	i++;
	(*len)++;
	}
	return ;
}
