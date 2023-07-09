/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbalbino <pbalbino@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 11:50:02 by pbalbino          #+#    #+#             */
/*   Updated: 2023/07/09 13:06:30 by pbalbino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_data	g_info;

void	reset_data()
{
	g_info.bit_index = 0;
	g_info.letter = 0;
	g_info.client_pid = 0;
}

// Quando o server enviar um dos sinais
void	signal_handler(int signal, siginfo_t *info, void *ucontext)
{
	if (g_info.client_pid != info->si_pid)
	reset_data();
	if (signal == SIGUSR1)
	{
		//ft_printf("\nSignal Intercepted: 1\n");
		ft_setbit(&g_info.letter, g_info.bit_index);
		g_info.bit_index++;
	}

	if (signal == SIGUSR2)
	{
		//ft_printf("\nSignal Intercepted: 0\n");
		//ft_setbit(&g_info.letter, g_info.bit_index);
		g_info.bit_index++;
	}
	//printf("%d\n", g_info.bit_index);
	if (g_info.bit_index == 8)
	{
		write (1, &g_info.letter, 1);
		g_info.bit_index = 0;
		g_info.letter = 0;
	}
	g_info.client_pid = info->si_pid;
}

// Funcao de registro

void register_signal(void)
{
	struct sigaction	act;

	ft_bzero(&act, sizeof(act));
	act.sa_sigaction = &signal_handler;
	act.sa_flags = SA_SIGINFO;
	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGUSR1);
	sigaddset(&act.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
}

int main(void)
{
	pid_t pid;

	reset_data();
	pid = getpid();
	ft_printf("%d", (int) pid);
	register_signal();
	while (1)
		sleep(1);
return (0);
}

/*para economizar linhar chamei a funcao reset_data no main, para iniciar
as variaveis*/
