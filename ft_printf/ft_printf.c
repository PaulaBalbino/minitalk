/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbalbino <pbalbino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 22:40:25 by pbalbino          #+#    #+#             */
/*   Updated: 2023/02/15 21:18:12 by pbalbino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_convert(va_list	ptr, char c, int *output)
{
	if (c == 'c')
		ft_char(va_arg(ptr, int), output);
	else if (c == 's')
		ft_string(va_arg(ptr, char *), output);
	else if (c == 'p')
		ft_pointer(va_arg(ptr, void *), output);
	else if (c == 'd' || c == 'i')
		ft_digit(va_arg(ptr, int), output);
	else if (c == 'u')
		ft_unsignedint(va_arg(ptr, unsigned int), output);
	else if (c == 'x')
		ft_lowerhexa(va_arg(ptr, unsigned int), output);
	else if (c == 'X')
		ft_upperhexa(va_arg(ptr, unsigned int), output);
	else if (c == '%')
	{
		write(1, "%", 1);
		*output = *output + 1;
	}
}

static void	ft_checknull(char c, int *output)
{
	if (c == 0)
	{
		write(1, "-1", 2);
		*output = *output + 2;
	}
}

static int	ft_printfrules(const char *str, int *output, int *i, va_list ptr)
{
	if (str[*i] == '%')
	{
		ft_checknull(str[*i + 1], output);
		if (str[*i + 1] != 'c' && str[*i + 1] != 's' && str[*i + 1] != 'p'
			&& str[*i + 1] != 'd' && str[*i + 1] != 'i' && str[*i + 1] != 'u'
			&& str[*i + 1] != 'x' && str[*i + 1] != 'X' && str[*i + 1] != '%')
		{
			write(1, "-1", 2);
			return (-1);
		}
		else
			ft_convert(ptr, str[*i + 1], output);
		(*i)++;
	}
	else
	{
		write(1, &str[*i], 1);
		*output = *output + 1;
	}
	(*i)++;
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		output;
	va_list	ptr;

	i = 0;
	output = 0;
	va_start(ptr, str);
	while (str[i] != 0)
	{
		if (ft_printfrules(str, &output, &i, ptr) == -1)
			return (-1);
	}
	return (output);
}
