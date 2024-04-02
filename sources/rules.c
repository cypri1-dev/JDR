/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 03:37:35 by cyprien           #+#    #+#             */
/*   Updated: 2024/04/02 16:08:10 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/story.h"

t_character init_statistics(t_character *character)
{
	clear_terminal();
	display_txt("chapters/init_stats.txt");
	printf("Appuyer sur 1 pour continuer !\n");
	scanf("%c", &character->answer);
	clear_input_buffer();
	update_character(character);
	switch(character->answer)
	{
		case '1':
			 roll_stats(character);
			 printf("Endurance [%d]/[%d]\n", character->endurance, character->max_endurance);
             printf("Habilite [%d]/[%d]\n", character->ability, character->max_ability);
             sleep(1);
             test_fight(character);
			 break;
		default:
			printf("Wrong choice !\n");
            sleep(1);
            return init_statistics(character);
	}
	return (*character);
}

t_character init_rules_3(t_character *character)
{
    clear_terminal();
    display_txt("chapters/init_rules_3.txt");
    printf("Appuyer sur 1 pour continuer !\n");
    scanf("%c", &character->answer);
    clear_input_buffer(); // Vider le tampon d'entrée
    update_character(character);
    switch(character->answer)
    {
        case '1':
            return init_statistics(character);
        default:
            printf("Wrong choice !\n");
            sleep(1);
            return init_rules_3(character);
    }
}

t_character init_rules_2(t_character *character)
{
    clear_terminal();
    display_txt("chapters/init_rules_2.txt");
    printf("Appuyer sur 1 pour continuer !\n");
    scanf("%c", &character->answer);
    clear_input_buffer(); // Vider le tampon d'entrée
    update_character(character);
    switch(character->answer)
    {
        case '1':
            return init_rules_3(character);
        default:
            printf("Wrong choice !\n");
            sleep(1);
            return init_rules_2(character);
    }
    // if (character.dead)
    //     return DEATH;
}

t_character init_rules(t_character *character)
{
    clear_terminal();
    display_txt("chapters/init_rules.txt");
    printf("Appuyer sur 1 pour continuer !\n");
    scanf("%c", &character->answer);
    clear_input_buffer(); // Vider le tampon d'entrée
    update_character(character);
    switch(character->answer)
    {
        case '1':
            return init_rules_2(character);
        default:
            printf("Wrong choice !\n");
            sleep(1);
            return init_rules(character);
    }
}
