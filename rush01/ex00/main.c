/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apatil <apatil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 16:05:11 by apatil            #+#    #+#             */
/*   Updated: 2025/04/05 16:17:48 by apatil           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s \"col1top col2top col3top col4top "
               "col1bottom col2bottom col3bottom col4bottom "
               "row1left row2left row3left row4left "
               "row1right row2right row3right row4right\"\n", argv[0]);
        return 1;
    }
    printf("Arg 1: %s\n", argv[1]);
    return 0;
}