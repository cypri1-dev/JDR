/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_input_output_display.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:22:10 by cyferrei          #+#    #+#             */
/*   Updated: 2023/11/03 15:17:01 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	main(void)
{	
	char	name[] = "";
	char	rep[] = "";

	printf("Ceci est un test\n");
	printf("Votre nom :");

	scanf("%s", name);

	printf("\e[1;1H\e[2J");
	
	printf("Bienvenu(e) %s.", name);
	printf("ES TU PRET(E) A TE LANCER DANS CETTE AVENTURE ?");
	printf("\n(ecrivez : yes)");

	scanf("%s", rep);
	if(strcmp(rep, "yes") != 0)
		printf("Dommage...");
	printf("Bien... COMMENCONS !");
	return(0);
}
