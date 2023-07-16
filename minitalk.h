/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbalbino <pbalbino@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 14:30:28 by pbalbino          #+#    #+#             */
/*   Updated: 2023/07/15 15:34:43 by pbalbino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <signal.h>
#include <stdio.h>
#include <strings.h>

#define BUFFER 1048576

typedef struct s_data
{
	int		bit_index;
	char	letter;
	int		client_pid;
	int		buf[BUFFER];
	int		getindex;
	int		addindex;
}	t_data;

void	print_options(void);
int		ft_atoi(const char *str);
void	ft_bzero(void *b, size_t len);
void	ft_setbit(char *c, int index);

/* char letter = 8 bits = 1 byte, armazena apenas uma letra */