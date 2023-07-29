/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbalbino <pbalbino@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:44:22 by pbalbino          #+#    #+#             */
/*   Updated: 2023/07/29 22:40:57 by pbalbino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	configure_signal(struct sigaction *signal)
{
	if (sigaction(SIGUSR1, signal, NULL) < 0)
		ft_printf("\nERROR - SIGUSR1 failed \n");
	if (sigaction(SIGUSR2, signal, NULL) < 0)
		ft_printf("\nERROR - SIGUSR2 failed \n");
}
