/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbalbino <pbalbino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 06:15:29 by pbalbino          #+#    #+#             */
/*   Updated: 2023/02/13 08:26:32 by pbalbino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const char *str, ...);
void	ft_char(char c, int *output);
void	ft_digit(int i, int *output);
void	ft_string(char *str, int *len);
void	ft_pointer(void *ptr, int *output);
void	ft_unsignedint(unsigned int nb, int *output);
void	ft_lowerhexa(unsigned int nb, int *output);
void	ft_upperhexa(unsigned int nb, int *output);

#endif
