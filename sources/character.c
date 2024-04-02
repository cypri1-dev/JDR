/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 03:09:35 by cyprien           #+#    #+#             */
/*   Updated: 2024/04/02 11:40:25 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/story.h"

t_character roll_stats(t_character *character)
{
    character->ability = (rand() % 6) + 6;
    character->max_ability = character->ability;
    character->endurance = (rand() % 6 + rand() % 6) + 12;
    character->max_endurance = character->endurance;
    character->luck = (rand() % 6) + 6;
    return (*character);
} 
