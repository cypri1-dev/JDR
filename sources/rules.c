/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyprien <cyprien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 03:37:35 by cyprien           #+#    #+#             */
/*   Updated: 2024/03/30 18:48:29 by cyprien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/story.h"

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
            printf("GG\n");
            return *character;
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