/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbalbino <pbalbino@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 14:30:28 by pbalbino          #+#    #+#             */
/*   Updated: 2023/07/09 12:23:37 by pbalbino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <signal.h>
#include <stdio.h>
#include <strings.h>

typedef struct s_data
{
	int		bit_index;
	char	letter;
	int		client_pid;
}	t_data;

void	print_options(void);
int		ft_atoi(const char *str);
void	ft_bzero(void *b, size_t len);
void	ft_setbit(char *c, int index);

/* char letter = 8 bits = 1 byte, armazena apenas uma letra */