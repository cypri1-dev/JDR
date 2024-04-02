/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_story.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:07:50 by cyprien           #+#    #+#             */
/*   Updated: 2024/04/02 15:14:09 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/story.h"

void clear_input_buffer() 
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

t_character update_character(t_character *charcater)
{
    charcater->last_answer = charcater->answer;
    return (*charcater);
}

static  t_character init_character(t_character *character)
{
    character->answer = '0';
    character->last_answer = '0';
    //...etc
    return(*character);
}

void    clear_terminal()
{
    system("clear");
    // printf("\033[2J");
    // printf("\033[H");   
}

void    display_txt(const char *chapter)
{
    FILE *file;
    int c;

    file = fopen(chapter, "r");
    if(!file)
    {
        printf("Can not open file : %s'\n", chapter);
        return;
    }
    while((c = fgetc(file)) != EOF)
        printf("%c", c);
    printf("\n\n");
    fclose(file);
}

int main (void)
{
    t_character *character;
    
    srand(time(NULL));    
    character = malloc(sizeof(t_character));
    if(!character)
        return (0);
    clear_terminal();
    display_txt("chapters/intro.txt");
    init_character(character);
    //printf("c.a : %c || c.la : %c\n", character->answer, character->last_answer);
    printf("1. C est parti ! 🗡️\n");
    printf("2. Attends j'ai pas finis de lire !!! 🛡️\n");
    printf("3. Oups ! Mauvaise application ! (exit) ❌\n");
    printf("4. Vas-y teste le menu ? (menu) 📒\n\n");
    printf("Votre choix : ");
    scanf("%c", &character->answer);
    clear_input_buffer();
    update_character(character);
    //printf("c.a : %c || c.la : %c\n", character->answer, character->last_answer);
    switch(character->answer)
    {
        case '1':
            init_rules(character);
            break;
        case '2':
            free(character);
            return main();
            break;
        case '3':
            clear_terminal();
            printf("A bientot mouhahaha\n");
            break;
        case '4':
            clear_terminal();
            display_menu();
            break;
        default:
            printf("Wrong choice looser!\n");
            free(character);
            sleep(1);
            return main();
    }
    if(character)
        free(character);
    return (0); 
}