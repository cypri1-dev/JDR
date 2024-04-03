/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 18:06:36 by cyprien           #+#    #+#             */
/*   Updated: 2024/04/03 11:50:09 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/story.h"

void    back_to_story(const char *chapter)
{
    clear_terminal();
    display_txt(chapter);
}

void display_menu(t_character *character, int (f)(void)) 
{    
    printf("\t\t\t\tMENU\n\n");
    printf("1. INVENTAIRE\t");
    printf("2. SAUVEGARDE\t");
    printf("3. PERSONNAGE\t");
    printf("4. RETOUR\t");
    printf("5. Quitter\t\n\n");
    printf("Votre choix : ");
    scanf("%s", &character->answer);
    clear_input_buffer();
    switch (character->answer)
    {
        case '1':
            //open_inventory();
            break;
        case '2':
            //save_game();
            break;
        case '3':
            //open_character();
        case '4':
            f();
            break;
    }
}