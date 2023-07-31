/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbalbino <pbalbino@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 11:50:02 by pbalbino          #+#    #+#             */
/*   Updated: 2023/07/30 19:15:43 by pbalbino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_data	g_info;

void	configure_signal(struct sigaction *signal)
{
	if (sigaction(SIGUSR1, signal, NULL) < 0)
		ft_printf("\nERROR - SIGUSR1 failed \n");
	if (sigaction(SIGUSR2, signal, NULL) < 0)
		ft_printf("\nERROR - SIGUSR2 failed \n");
}

void	print_message(void)
{
	int	i;

	i = 0;
	while (i < g_info.letterindex && g_info.buf[i] != 0)
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

/*

buffer eh um grande vetor de chars.

*/

static void	signal_handler(int signal, siginfo_t *info, void *context)
{
	usleep(100);
	(void) context;
	if (info->si_pid > 0)
		g_info.client_pid = info->si_pid;
	if (signal == SIGUSR1)
		process_bit (1);
	else if (signal == SIGUSR2)
		process_bit (0);
	kill (g_info.client_pid, SIGUSR1);
}

/*
usleep - suspend execution for microsecond intervals (neste caso,
100 microseconds) minimo necessario para tratar um sinal e avisar
o client que o sinal foi tratado (equivalente do ack).

context: nao eh utilizado; (void) silencia o erro: unused parameter
'context'.

info->si_pid: eh o PID do client, salva esse valor em client_pid para
distinguir os clients (sobrescreve o valor) e enviar o ack do recebimento.

process_bit (signal == SIGUSR1):

kill sera enviado pelo server para o client avisando que o bit chegou,
para que o proximo seja enviado.


*/

int	main(void)
{
	struct sigaction	s_server;
	pid_t				pid;

	g_info.bit_index = 0;
	g_info.letter = 0;
	g_info.client_pid = 0;
	g_info.letterindex = 0;
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

/*
main: eh basicamente a configuracao como o sinal deve ser tratado e qual sinal.

getpid eh uma funcao do sistema

sigemptyset: The sigemptyset() function initialises the signal e zera os sinIS

The sigaction structure is defined as something like:

           struct sigaction {
               1 - void     (*sa_handler)(int);
               2 - void     (*sa_sigaction)(int, siginfo_t *, void *);
               sigset_t   sa_mask; (nao eh usado diretamente, a ft sigaction preenche o mask)
               int        sa_flags;
               void     (*sa_restorer)(void);
           };


sa_flags: define comportamento, behaviour. Define se ira chamar a funcao 1 ou 2
(usando o flag usa a 2 por default).

sa_mask: define quais sinais serao tratados pela funcao (no caso: SIGUSR1 E 2);

obs: essa estrutura esta no .h do sistema.

s_server.sa_sigaction = signal_handler  >> sa_sigaction eh um ponteiro que
precisa ser configurado para apontar para a ft que ira tratar os sinais recebidos
do client (obs: segue o prototipo da funcao 2 da struct)

SA_SIGINFO: eh uma flag que o sistema deve chamar a ft 2 e nao a 1.

**** SA_RESTART:

configure_signal(&s_server); define quais sinais devem ser tratados pela funcao.

while eh infinito, ate receber um sinal (tira o pause). Na sequencia ele pausa
novamente. vide man pause: pause – stop until signal
DESCRIPTION
     Pause is made obsolete by sigsuspend(2).

     The pause() function causes the calling thread to pause until a signal is
     received from either the kill(2) function or an interval timer.  (See
     setitimer(2).) Upon termination of a signal handler started during a
     pause(), the pause() call will return.

	 neste caso eh uma thread unica
*/
