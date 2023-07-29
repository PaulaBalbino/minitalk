/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbalbino <pbalbino@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 14:30:28 by pbalbino          #+#    #+#             */
/*   Updated: 2023/07/29 22:41:10 by pbalbino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "ft_printf.h"
# include <unistd.h>
# include <signal.h>
# include <stdio.h>
# include <strings.h>

# define BUFFER 1048576

typedef struct s_data
{
	int		bit_index;
	char	letter;
	int		client_pid;
	int		buf[BUFFER];
	int		letterindex;
}	t_data;

int		ft_getbit(char c, int bit);
void	ft_setbit(char *c, int index);
int		ft_check_serverpid(int pid_s);
int		ft_atoi(const char *str);
void	configure_signal(struct sigaction *signal);

#endif

/* char letter = 8 bits = 1 byte, armazena apenas uma letra */