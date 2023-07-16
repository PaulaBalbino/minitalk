/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbalbino <pbalbino@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 11:50:02 by pbalbino          #+#    #+#             */
/*   Updated: 2023/07/16 19:59:56 by pbalbino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_data	g_info;

void	reset_data(void)
{
	g_info.bit_index = 0;
	g_info.letter = 0;
	g_info.client_pid = 0;
	g_info.letterindex = 0;
}

void	print_message(void)
{
	int	i;

	i = 0;
	while (i < g_info.letterindex || g_info.buf[i] != 0)
	{
		write (1, &g_info.buf[i], 1);
		i++;
	}
}

void	process_bit(int bit)
{
	g_info.letter = g_info.letter | bit;
	g_info.bit_index++;
	if (g_info.bit_index == 8)
	{
		g_info.buf[g_info.letterindex] = g_info.letter;
		g_info.bit_index = 0;
		g_info.letter = 0;
		if (g_info.buf[g_info.letterindex] == 0)
		{
			print_message();
			g_info.letterindex = 0;
		}
		else
			g_info.letterindex++;
	}
	g_info.letter <<= 1;
}

// Quando o server enviar um dos sinais
static void	signal_handler(int signal, siginfo_t *info, void *context)
{
	usleep(100);
	(void) context;
	(void) info;
	if (info->si_pid != 0)
		g_info.client_pid = info->si_pid;
	if (signal == SIGUSR1 || signal == SIGUSR2)
		process_bit (signal == SIGUSR1);
	kill (g_info.client_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	s_server;
	pid_t				pid;

	reset_data();
	pid = getpid();
	ft_printf("My PID is %d\n", (int) pid);
	sigemptyset(&s_server.sa_mask);
	s_server.sa_sigaction = signal_handler;
	s_server.sa_flags = SA_SIGINFO | SA_RESTART;
	configure_signal(&s_server);
	while (1)
		pause();
	return (0);
}

/*para economizar linhar chamei a funcao reset_data no main, para iniciar
as variaveis*/
