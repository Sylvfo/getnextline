/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmalloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:13:09 by marvin            #+#    #+#             */
/*   Updated: 2023/12/05 10:13:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_testmalloc(char * t)
{
	static char		*line1;
	char			*line2;
	
	line1 = malloc(10 * sizeof(char));
	line2 = "Soie ";
	line2 = malloc(10 * sizeof(char));

	return (line1);
}

int main(void)
{
	char	*test = "joie et sentiments perdus";

	printf("%s\n", ft_testmalloc(test));
	printf("%s\n", ft_testmalloc(test));
	return (0);
}