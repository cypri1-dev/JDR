/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:06:38 by cyferrei          #+#    #+#             */
/*   Updated: 2024/11/22 16:49:19 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monsters/Monsters.hpp"
#include "character/Character.hpp"
#include "character/Inventory.hpp"
#include "story/Menu.hpp"
#include <sstream>

int main (void) {

	Monsters m1("Barbarian", 6, 7);
	Monsters m2("test", 0, 0);

	// std::cout << m1 << std::endl;
	
	Character character("Adshum", 999, 999, 10);
	character._inventory.setGold(2);
	character._inventory.setItems(0, "chaussette");
	character._inventory.setItems(1, "potion");


	// std::cout << character << std::endl;

	Menu menu;

	menu.displayMenu(character, "1", menu.getChapterText(1));
	return (0);
}
