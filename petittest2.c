/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   petittest2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 22:52:45 by marvin            #+#    #+#             */
/*   Updated: 2023/11/30 22:52:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void exampleFunction() {
    // Variable statique pointeur de type char
    static char *staticCharPointer = "Hello, world!";

    // Utilisation du pointeur
    printf("Contenu pointé par le pointeur statique char : %s\n", staticCharPointer);
}

int main() {
    exampleFunction();
    exampleFunction(); // La variable conserve sa valeur entre les appels

    return 0;
}
