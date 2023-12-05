/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testfiledescriptor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:37:32 by marvin            #+#    #+#             */
/*   Updated: 2023/11/30 19:37:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_putchar_terminal(char c)
{
	write(1, &c, 1);
}

void	ft_putchar_test_file(char *c)
{
	int	fd;
	int	i;

	i = 0;
	fd = open("base.txt", O_RDWR);
	if (fd > 0)
	{
		while (c[i] != 0)
		{
			write (fd, &c[i], 1);
			i++;
		}
	}
	else
		write(2, "test.txt not found.\n", 20);
}

int	main(void)
{
	ft_putchar_terminal('T');
	ft_putchar_test_file("Maluma Baby!\nVamo' a ser feliz\nFelices los 4\nYo te acepto el trato");
	return (0);
}
