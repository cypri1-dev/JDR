/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Menu.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:59:52 by cyferrei          #+#    #+#             */
/*   Updated: 2024/11/21 17:36:46 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Menu.hpp"
#include <cstddef>
#include <cstdio>
#include <sstream>
#include <string>
#include <unordered_map>
#include <utility>

Menu::Menu() {
	std::cout << BOLD_ON YELLOW << "Default (Menu) constructor called!" << BOLD_OFF << std::endl;
	std::vector<std::string> main_menu_options = {
		"Display Character", "Display Inventory",
		"Save", "Exit"
	};
	std::vector<std::string> character_menu_options = {
		"Main menu",
	};
	this->menu_options.push_back(main_menu_options);
	this->menu_options.push_back(character_menu_options);
}

Menu::~Menu() {
	std::cout << BOLD_ON RED << "Default (Menu) destructor called!" << BOLD_OFF << std::endl;
}

/************************************************************************************************/

void Menu::displayCharacter(const Character &c)const {

	stringstream text;
	text << BOLD_ON YELLOW << "*****CHARACTER******" << BOLD_OFF << std::endl << std::endl;
	text << BOLD_ON << "[Nom]: " << BLUE << c.getName() << BOLD_OFF << std::endl;
	text << BOLD_ON << "[Endurance]: " << c.getEP() << BOLD_OFF << "/" << BOLD_ON BLUE << c.getBaseEP() << BOLD_OFF << std::endl;
	text << BOLD_ON << "[Habilite]: " << c.getSP() << BOLD_OFF << "/" << BOLD_ON BLUE << c.getBaseSP() << BOLD_OFF << std::endl;
	text << BOLD_ON << "[Chance]: " << c.getLP() << BOLD_OFF << "/" << BOLD_ON BLUE << c.getBaseLP() << BOLD_OFF << std::endl;


	this->displayMenu(CHARACTER_MENU, text);
	int selectedIndex = this->displayMenu(MAIN_MENU);
	switch (selectedIndex) {
		case 0: this->displayCharacter(c); break;
		case 1: this->displayInventory(c._inventory); break;
		case 2: break;
		case 3: break;
	}
}

/************************************************************************************************/


void Menu::displayInventory(const Inventory &inv)const {
	std::cout << BOLD_ON YELLOW << "*****INVENTORY******" << BOLD_OFF << std::endl << std::endl;
	for (size_t i = 0; inv.getItems(i).size(); i++)
		std::cout << BOLD_ON BLUE << "[" << i << "]" << BOLD_OFF << ": " << BOLD_ON << inv.getItems(i) << BOLD_OFF << std::endl;
}

/************************************************************************************************/

void Menu::clearConsole() const{
	std::cout << "\033[2J\033[1;1H";
}

char getch() {
	char ch;
	read(STDIN_FILENO, &ch, 1); // Lit un caractère depuis stdin
	return ch;
}

void configureTerminal(bool enable) {
	static struct termios oldt, newt;
	if (enable) {
		tcgetattr(STDIN_FILENO, &oldt); // Sauvegarde des paramètres actuels
		newt = oldt;
		newt.c_lflag &= ~(ICANON | ECHO); // Mode non canonique, désactive l'écho
		tcsetattr(STDIN_FILENO, TCSANOW, &newt); // Applique les paramètres
	} else {
		tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // Restaure les paramètres
	}
}

typedef void (Menu::*menu_func)(void); 

int Menu::displayMenu(e_menu mode, const stringstream& text) const{
	size_t selectedIndex = 0;
	char input = 0;

	vector<string> options = this->menu_options[mode];

	configureTerminal(true); // Passe en mode non canonique
	while (true) {
		clearConsole();
		std::cout << "*****Menu*****\n\n";

		std::cout << text.str() << std::endl;

		for (size_t i = 0; i < options.size(); ++i) {
			if (i == selectedIndex) {
				std::cout << " > " << options[i] << " <\n"; // Option sélectionnée
			} else {
				std::cout << "   " << options[i] << "\n";   // Option non sélectionnée
			}
		}

		input = getch(); // Lit un caractère
		if (input == '\033') { // Début d'une séquence d'échappement
			getch(); // Ignore '['
			input = getch(); // Lit le code final ('A', 'B', etc.)
			if (input == 'A') {
				selectedIndex = (selectedIndex - 1 + options.size()) % options.size(); // Flèche haut
			} else if (input == 'B') {
				selectedIndex = (selectedIndex + 1) % options.size(); // Flèche bas
			}
		} else if (input == '\n') { // ""Entrée" pour valider
			break;
		}
	}
	configureTerminal(false); // Restaure les paramètres du terminal

	clearConsole();
	std::cout << "You selected: " << options[selectedIndex] << "\n";
	return selectedIndex;
	
}

/************************************************************************************************/
