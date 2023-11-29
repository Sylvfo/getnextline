/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:33:18 by sforster          #+#    #+#             */
/*   Updated: 2023/11/29 18:44:16 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

/*
int	ft_add(int x)
{
	int	sum;

	sum = 0;
	sum += x;
	return (sum); 
}
*/

int	ft_add_static(int x)
{
	static int	sum;

	sum = 0;
	sum += x;
	return (sum);
}

int main(void)
{
/*	printf("%d \n", ft_add(5));
	printf("%d \n", ft_add(5));
	printf("%d \n", ft_add(5));*/
	printf("%d \n", ft_add_static(10));
	printf("%d \n", ft_add_static(5));
	printf("%d \n", ft_add_static(5));
	return (0);
}