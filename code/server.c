/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbalbino <pbalbino@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 11:50:02 by pbalbino          #+#    #+#             */
/*   Updated: 2023/07/08 17:49:59 by pbalbino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// PARAMOS NA CRIACAO DA FUNCAO SETBIT, PROVAVELMENTE SERA NECESSARIO CRIAR UM STRUCT
// VER OUTROS CODIGOS 

#include "minitalk.h"

int g_count;

// Quando o server enviar um dos sinais
void	signal_handler(int signal)
{
	if (signal == SIGUSR1)
	{
		ft_printf("\nSignal Intercepted: 1\n");
		ft_setbit()
		g_count++;
	}

	if (signal == SIGUSR2)
	{
		ft_printf("\nSignal Intercepted: 0\n");
		g_count++;
	}
}


// Funcao de registro
void register_signal_one(void)
{
	// Declare the sigaction structure
	struct sigaction	act;

	// Set all of the structure's bits to 0 to avoid errors
	// relating to uninitialized variables...
	ft_bzero(&act, sizeof(act));
	// Set the signal handler as the default action
	act.sa_handler = &signal_handler;

	// Apply the action in the structure to the
	// SIGINT signal (ctrl-c)
	sigaction(SIGUSR1, &act, NULL);
}

void register_signal_zero(void)
{
	struct sigaction	act;

	ft_bzero(&act, sizeof(act));
	act.sa_handler = &signal_handler;

	sigaction(SIGUSR2, &act, NULL);
}

#include "minitalk.h"

int main(void)
{
	pid_t PID;

	g_count = 0;
	PID = getpid();
	ft_printf("%d", (int) PID);

register_signal_one();
register_signal_zero();

while (1)
{
	sleep(1);
}
return (0);
}
