/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   petittest.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 22:40:45 by marvin            #+#    #+#             */
/*   Updated: 2023/11/30 22:40:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> 
int fun(int x) 
{ 
	return (x+5); 
} 

int main() 
{ 
	int y = fun(20); 
	printf("%d ", y); 
}