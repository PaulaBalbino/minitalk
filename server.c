/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbalbino <pbalbino@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 11:50:02 by pbalbino          #+#    #+#             */
/*   Updated: 2023/07/15 16:40:16 by pbalbino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

t_data	g_info;

void	reset_data()
{
	g_info.bit_index = 0;
	g_info.letter = 0;
	g_info.client_pid = 0;
	g_info.getindex = 0;
	g_info.addindex = 0;

}

// Quando o server enviar um dos sinais
void	signal_handler(int signal, siginfo_t *info, void *ucontext)
{
	(void) ucontext;
	(void) info;
	g_info.buf[g_info.addindex] = (signal == SIGUSR1);
	//printf("\nsignal_handler %d",g_info.buf[g_info.addindex] );
	if (g_info.addindex >= BUFFER)
		g_info.addindex = 0;
	else
		g_info.addindex++;
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
	ft_printf("My PID is %d\n", (int) pid);
	register_signal();
	while (1)
	{
		if (g_info.getindex < g_info.addindex)
		{
			g_info.letter = g_info.letter | (g_info.buf[g_info.getindex]);
			//printf("\nmain %d", g_info.buf[g_info.getindex]);
			g_info.bit_index++;
			g_info.getindex++;

			if (g_info.bit_index == 8)
			{
				//printf("\n%c   %x", g_info.letter,g_info.letter );
				write (1, &g_info.letter, 1);
				g_info.bit_index = 0;
				g_info.letter = 0;
			}
			g_info.letter <<= 1;
		}
	}
return (0);
}

/*para economizar linhar chamei a funcao reset_data no main, para iniciar
as variaveis*/
