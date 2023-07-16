/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbalbino <pbalbino@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:44:22 by pbalbino          #+#    #+#             */
/*   Updated: 2023/07/16 20:03:52 by pbalbino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// Funcao de registro
void	register_signal(struct sigaction *act,
	void (*signal_handler)(int, siginfo_t *, void *) )
{
	sigemptyset(&act->sa_mask);
	act->sa_sigaction = signal_handler;
	act->sa_flags = SA_SIGINFO | SA_RESTART;
	sigaction(SIGUSR1, act, NULL);
	sigaction(SIGUSR2, act, NULL);
}

void	configure_signal(struct sigaction *signal)
{
	if (sigaction(SIGUSR1, signal, NULL) < 0)
		ft_printf("\n ERROR - SIGUSR1 failed \n");
	if (sigaction(SIGUSR2, signal, NULL) < 0)
		ft_printf("\nERROR - SIGUSR2 failed \n");
}
