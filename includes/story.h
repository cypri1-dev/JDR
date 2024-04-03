/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   story.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:10:29 by cyprien           #+#    #+#             */
/*   Updated: 2024/04/03 12:35:27 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*all includes*/

#include "character.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <linux/limits.h>

/*all prototypes*/

void display_menu(t_character *character, int (f)(void));
void    display_txt(const char *chapter);
void    clear_terminal();
void clear_input_buffer();

t_character update_character(t_character *charcater);
t_character roll_stats(t_character *character);

t_character init_rules(t_character *character);
t_character init_rules_2(t_character *character);
t_character init_rules_3(t_character *character);

void	test_fight(t_character *character);
int	initiative_roll(t_character *character, int *monster_endu, int *monster_ability, char *monster_name);
void	fight(t_character *character, char *monster_name, int *monster_endu, int *monster_ability, int luck_allowed, int escape_allowed);
int	luck_roll(t_character *character);

int main (void);
