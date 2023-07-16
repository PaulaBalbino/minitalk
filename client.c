/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbalbino <pbalbino@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 11:49:50 by pbalbino          #+#    #+#             */
/*   Updated: 2023/07/15 16:48:15 by pbalbino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int ft_getbit(char c, int bit)
{
	int b;

	b = (c >> bit) & 1;
	return(b);
}

void ft_kill(int pid, int bit)
{
	if (bit == 0)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	return;
}

int main(int ac, char **av)
{
	int pid;
	int i;
	int bitcounter;

	i = 0;
	if (ac != 3)
		return (0);
	pid = ft_atoi(av[1]);
	while (av[2][i] != 0)
	{
		bitcounter = 8;
		while(bitcounter > 0)
		{
			bitcounter = bitcounter - 1;
			if (av[2][i] & (1 << bitcounter))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(1500);
		}
		i++;
	}
}