/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbalbino <pbalbino@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 11:49:50 by pbalbino          #+#    #+#             */
/*   Updated: 2023/07/08 17:16:50 by pbalbino         ###   ########.fr       */
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
	if (bit == 1)
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
	{
		print_options();
		return (0);
	}
	pid = ft_atoi(av[1]);
	while (av[2][i] != 0)
	{
		bitcounter = 0;
		while(bitcounter < 8)
		{
			ft_kill(pid, ft_getbit(av[2][i], bitcounter));
			bitcounter++;
			sleep(1);
		}
		i++;
	}
}