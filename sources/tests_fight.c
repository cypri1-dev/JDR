/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_fight.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:56:42 by cyferrei          #+#    #+#             */
/*   Updated: 2024/04/03 12:35:33 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/story.h"

void	test_fight(t_character *character)
{
	char *monster_name = "Barbarian";
	int barbarian_endu = 6;
	int barbarian_ability = 7;
	clear_terminal();
	display_txt("chapters/tests_fight.txt");
	printf("Appuyer sur 1 pour continuer !\n");
	scanf("%c", &character->answer);
	clear_input_buffer();
	switch (character->answer)
	{
		case '1':
			fight(character, monster_name, &barbarian_endu, &barbarian_ability, 1, 1);
			break;
	
		default:
			printf("Wrong choice !\n");
            sleep(1);
			test_fight(character);
	}
}