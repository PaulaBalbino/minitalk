/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbalbino <pbalbino@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 14:37:36 by pbalbino          #+#    #+#             */
/*   Updated: 2023/07/30 09:58:03 by pbalbino         ###   ########.fr       */
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

int	ft_check_serverpid(int pid_s)
{
	if (kill(pid_s, 0) < 0 || pid_s <= 0)
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

/*
(kill(pid_s, 0) < 0) >> verifica se o PID eh valido

The kill() function sends the signal specified by sig to pid, a process
or a group of processes.  Typically, Sig will be one of the signals
specified in sigaction(2).  A value of 0, however, will cause error checking
to be performed (with no signal being sent). This can be used to check the
validity of pid.

*/