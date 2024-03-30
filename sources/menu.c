/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyprien <cyprien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 18:06:36 by cyprien           #+#    #+#             */
/*   Updated: 2024/03/30 02:29:47 by cyprien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/story.h"

void    back_to_story(const char *chapter)
{
    clear_terminal();
    display_txt(chapter);
}

void display_menu(void)
{
    int choice;
    
    printf("\t\t\t\tMENU\n\n");
    printf("1. INVENTAIRE\t");
    printf("2. SAC A DOS\t");
    printf("3. SAUVEGARDE\t");
    printf("4. PERSONNAGE\t");
    printf("5. RETOUR\t");
    printf("6. Quitter\t\n\n");
    printf("Votre choix : ");
    scanf("%d", &choice);
    switch (choice)
    {
        case 5:
            clear_terminal();
            main();
            break;
    }
}