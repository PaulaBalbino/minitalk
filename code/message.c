/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbalbino <pbalbino@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 14:35:03 by pbalbino          #+#    #+#             */
/*   Updated: 2023/07/08 14:35:22 by pbalbino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i] != 0)
	{
		write (fd, &s[i], 1);
	i++;
	}
}

void	print_options(void)
{
	ft_putstr_fd("\n\n===============  Fractol Project  ===============\n\n", 1);
	ft_putstr_fd("You can choose between Julia and Mandelbrot:\n", 1);
	ft_putstr_fd("\tJulia\n", 1);
	ft_putstr_fd("\tMandelbrot\n", 1);
	ft_putstr_fd("For Julia, please note that the values must be \n", 1);
	ft_putstr_fd("between -2.0 and 2.0, with a decimal point.\n\n", 1);
	ft_putstr_fd("You can use the mouse wheel to zoom in/out.\n\n", 1);
	ft_putstr_fd("Press ESC or close window to exit.\n", 1);
	ft_putstr_fd("================================================\n\n\n", 1);
}
