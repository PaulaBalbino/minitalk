/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbalbino <pbalbino@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 14:37:36 by pbalbino          #+#    #+#             */
/*   Updated: 2023/07/16 19:52:03 by pbalbino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_setbit(char *c, int index)
{
	*c = *c | (1 << index);
}

int	ft_getbit(char c, int bit)
{
	int	b;

	b = (c >> bit) & 1;
	return (b);
}

// o zero verifica a existencia do processo
int	ft_check_serverpid(int pid_s)
{
	if (kill(pid_s, 0) < 0)
	{
		ft_printf("\n\nIncorrect PID number, please check\n\n");
		return (-1);
	}
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != 0)
	{
		result = result * 10;
		result = result + str[i] - '0';
		i++;
	}
	return (result * sign);
}
