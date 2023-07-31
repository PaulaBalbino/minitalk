/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbalbino <pbalbino@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 11:49:50 by pbalbino          #+#    #+#             */
/*   Updated: 2023/07/30 09:46:32 by pbalbino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signal)
{
	(void) signal;
}

void	register_signal_client(struct sigaction *ack)
{
	sigemptyset(&ack->sa_mask);
	ack->sa_flags = SA_RESTART;
	ack->sa_handler = signal_handler;
	sigaction(SIGUSR1, ack, NULL);
	sigaction(SIGUSR2, ack, NULL);
}

int	send_null_terminator(int pid_s)
{
	int	bitcounter;

	bitcounter = 8;
	while (bitcounter > 0)
	{
		bitcounter = bitcounter - 1;
		if (kill(pid_s, SIGUSR2) < 0)
			return (-1);
		pause();
	}
	return (0);
}

int	ft_sendbyte(char byte, int pid_s)
{
	int	bitcounter;

	bitcounter = 8;
	while (bitcounter > 0)
	{
		bitcounter = bitcounter - 1;
		if (byte & (1 << bitcounter))
		{
			if (kill(pid_s, SIGUSR1) < 0)
				return (-1);
		}
		else
		{
			if (kill(pid_s, SIGUSR2) < 0)
				return (-1);
		}
		pause();
	}
	return (0);
}

int	main(int ac, char **av)
{
	int					pid_s;
	int					i;
	struct sigaction	ack;

	i = 0;
	if (ac != 3)
	{
		ft_printf("\n\nCheck the number of parameters\n\n");
		return (0);
	}
	pid_s = ft_atoi(av[1]);
	if (ft_check_serverpid(pid_s) == -1)
		return (-1);
	register_signal_client(&ack);
	while (av[2][i] != 0)
	{
		if (ft_sendbyte(av[2][i], pid_s) == -1)
			return (-1);
		i++;
	}
	send_null_terminator(pid_s);
	return (0);
}
