/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 02:12:25 by cyprien           #+#    #+#             */
/*   Updated: 2024/04/02 14:06:27 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*main character structure*/

#define DEATH 10
#define EQUIPED 1
#define UNEQUIPED 0


typedef struct s_character
{
    char answer;
    char last_answer;

    int ability;
    int max_ability;
    int endurance;
    int max_endurance;
    int luck;
    
    const char *name;
    //...etc
}             t_character;

typedef struct s_inventory
{
     char   **bag;
     int    *equiped;
     int    size;
}  t_inventory;

// void add_to_inventory(t_inventory *holding, char *item){
    
//     char **newbag = calloc(holding->size + 1, sizeof(char *));
//     char *new_equiped = calloc(holding->size + 1, sizeof(int));

//     int i = 0;
//     for(i; i < holding->size; i++)
//         newbag[i] = strdup(holding->bag[i]);
//     newbag[i] = item;
    
//     i = 0;
//     for (i; i < holding->size; i++)
//         new_equiped[i] = holding->equiped[i];
//     new_equiped[i] = UNEQUIPED;

//     for (int i = 0; i < holding->size; i++)
//         free(holding->bag[i]);
//     free(holding->bag);
//     free(holding->equiped);

//     holding->bag = newbag;
//     holding->equiped = new_equiped;
// }