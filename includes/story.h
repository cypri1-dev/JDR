/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   story.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyprien <cyprien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:10:29 by cyprien           #+#    #+#             */
/*   Updated: 2024/03/30 21:11:05 by cyferrei         ###   ########.fr       */
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

void display_menu(void);
void    display_txt(const char *chapter);
void    clear_terminal();
t_character update_character(t_character *charcater);
t_character init_rules(t_character *character);
t_character init_rules_2(t_character *character);
t_character init_rules_3(t_character *character);
t_character roll_stats(t_character *character);
void clear_input_buffer();

int main (void);
