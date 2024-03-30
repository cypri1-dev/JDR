/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyprien <cyprien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 03:09:35 by cyprien           #+#    #+#             */
/*   Updated: 2024/03/30 21:09:24 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/story.h"

t_character roll_stats(t_character *character)
{
    character->ability = (rand() % 6) + 6;
    character->max_ability = character->ability;
    character->endurance = (2 * (rand() % 6)) + 12;
    character->max_endurance = character->endurance;
    character->luck = (rand() % 6) + 6;
    return (*character);
} 
