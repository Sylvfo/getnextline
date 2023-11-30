/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:33:18 by sforster          #+#    #+#             */
/*   Updated: 2023/11/30 21:47:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_add(int x)
{
	int	sum = 0;

	sum += x;
	return (sum);
}

int	ft_add_static(int x)
{
	static int	sum = 0;

	sum += x;
	return (sum);
}

int	main(int argc, char *argv[])
{
	printf("%d \n", ft_add(5));
	printf("%d \n", ft_add(5));
	printf("%d \n", ft_add(5));
	printf("%i \n", ft_add_static(5));
	printf("%i \n", ft_add_static(12));
	printf("%i \n", ft_add_static(5));
	return (0);
}
