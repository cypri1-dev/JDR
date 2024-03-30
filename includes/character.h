/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyprien <cyprien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 02:12:25 by cyprien           #+#    #+#             */
/*   Updated: 2024/03/30 18:31:50 by cyprien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*main character structure*/

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
