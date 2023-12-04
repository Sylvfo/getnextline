/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testreadstash.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 08:59:54 by sforster          #+#    #+#             */
/*   Updated: 2023/12/04 19:10:13 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_read_stash(char *stash)
{ 
	int	i;

	i = 0;
	if (!stash)
		return (-1);
	while (stash[i] != '\n' && stash[i] != 0)
	{
		i++;
	}
	return(i);
}

int	main(void)
{
	printf("%d", ft_read_stash("Petit \n grand"));
	return (0);
}