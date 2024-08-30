/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fight.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:20:04 by cyferrei          #+#    #+#             */
/*   Updated: 2024/08/30 12:02:13 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/story.h"

int	initiative_roll(t_character *character, int *monster_endu, int *monster_ability, char *monster_name)
{
	int	monster_attack_force = 0;
	int charcater_attack_force = 0;

	monster_attack_force = (rand() % 6) + (rand() % 6) + *monster_ability;
	charcater_attack_force = (rand() % 6) + (rand() % 6) + character->ability;
	if(charcater_attack_force > monster_attack_force)
	{
		// printf("m_a_f = %d|| c_a_f = %d\n", monster_attack_force, charcater_attack_force);
		printf("Vous blessez %s !\n", monster_name);
		return(CHARACTER_ATTACK);
	}
	else if(charcater_attack_force == monster_attack_force)
	{
		// printf("m_a_f = %d|| c_a_f = %d\n", monster_attack_force, charcater_attack_force);
		printf("Vos forces d'attaque s'egalent !\n");
		sleep(2);
		initiative_roll(character, monster_endu, monster_ability, monster_name);
	}
	else
	{
		// printf("m_a_f = %d|| c_a_f = %d\n", monster_attack_force, charcater_attack_force);
		printf("%s vous blesse !\n", monster_name);
		return (MONSTER_ATTACK);
	}
	return (0);
}
int	luck_roll(t_character *character)
{
	int roll = (rand() % 6) + (rand() % 6);
	
	if (roll <= character->luck)
		return (LUCK_ATTACK);
	else
		return (UNLUCK_ATTACK);
}

void	fight(t_character *character, char *monster_name, int *monster_endu, int *monster_ability, int luck_allowed, int escape_allowed)
{
	int lucky = ZERO_INIT;
	
	while(character->endurance > 0 && *monster_endu > 0)
	{
		lucky = 0;
		if(initiative_roll(character, monster_endu, monster_ability, monster_name) == CHARACTER_ATTACK)
		{
			if (luck_allowed == 1)
			{
				printf("Vous avez la possibilite de TENTEZ VOTRE CHANCE : Cela peut s'averer benefique ou... catastrophique !\nAppuyer sur 1 pour tentez votre chance ou 2 pour poursuivre le combat normalement :\n");
				scanf("%s", &character->answer);
				clear_input_buffer();
				switch (character->answer)
				{
					case '1':
						if (luck_roll(character) == LUCK_ATTACK)
						{
							lucky = 1;
							printf("Vous etes chanceux : COUP CRITIQUE DANS SA MERE !\n");
							*monster_endu -= 4;
							printf("monster endu : %d || character endu : %d / %d\n", *monster_endu, character->endurance, character->max_endurance);
							sleep(2);
						}
						else
						{
							lucky = 1;
							printf("Vous etes malchanceux : COUP CRITIQUE DANS TA MERE !\n");
							character->endurance -= 4;
							printf("monster endu : %d || character endu : %d / %d\n", *monster_endu, character->endurance, character->max_endurance);
							sleep(2);
						}
						break;
					case '2':
						break;
					default:
						printf(WRONG_CHOICE);
            			sleep(1);
						fight(character, monster_name, monster_endu, monster_ability, luck_allowed, escape_allowed);
				}
			}
			if(lucky == 0)
			{
				*monster_endu -= 2;
				printf("monster endu : %d || character endu : %d / %d\n", *monster_endu, character->endurance, character->max_endurance);
				sleep(2);
			}
		}
		else
		{	
			character->endurance -= 2;
			printf("monster endu : %d || character endu : %d / %d\n", *monster_endu, character->endurance, character->max_endurance);
			sleep(2);
		}
	}
	if(character->endurance == 0)
		printf("Vous etes mort !\n");
	else
		printf("Vous sortez victorieux de ce combat ! Felicitations !\n");
}