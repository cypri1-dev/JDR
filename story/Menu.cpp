/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Menu.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:59:52 by cyferrei          #+#    #+#             */
/*   Updated: 2024/11/26 14:16:01 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Menu.hpp"
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdarg>

void Menu::addMenuOptions(...) {
        va_list args;
        va_start(args, this);

		vector<string> options;
		const char *key_str = va_arg(args, const char *);
		string key = string(key_str);
        while (true) {
            const char* str = va_arg(args, const char*);
            if (!str) break; // End of arguments (use nullptr as a sentinel)
            options.push_back(std::string(str));
        }
		this->menu_options[key] = options;
        va_end(args);  // Clean up
    }

Menu::Menu() {
	std::cout << BOLD_ON YELLOW << "Default (Menu) constructor called!" << BOLD_OFF << std::endl;

	this->addMenuOptions("Main Menu", "Display Character", "Display Inventory", "Save", "Exit", 0);
	this->addMenuOptions("Display Character", "Main Menu", "Display Inventory", "Save", "Exit", 0);
	this->addMenuOptions("Display Inventory", "Main Menu", "Display Character", "Save", "Exit", 0);
	this->addMenuOptions("Save", "Main Menu", "Display Character", "Display Inventory", "Exit", 0);
	this->addMenuOptions("1", "Main Menu", "71", "278", 0);
	this->addMenuOptions("2", "Main Menu", "16", "249", 0); // tenter sa chance! -> 16 if false 249 if true!
	// this->addMenuOptions("2", "Main Menu", (Luck(6, 4) == true) ? "16" : "249", 0); // tenter sa chance! -> 16 if false 249 if true!
	this->addMenuOptions("71", "Main Menu", "345", "18", 0);


	ifstream file = ifstream(BOOK_PATH);

	size_t i = 0;
	for(string line; getline(file, line);) {
		if (i++ == 0) continue;
		size_t start = line.find(":") + 2;
		size_t end = line.rfind(",") - 1;
		line = line.substr(start, end - start);
		for (size_t newline_pos; (newline_pos = line.find("\\n", 0)) != string::npos;) {
			line.replace(newline_pos, 2, "\n");
		}
		this->chapters.push_back(line);
	}
}

Menu::~Menu() {
	std::cout << BOLD_ON RED << "Default (Menu) destructor called!" << BOLD_OFF << std::endl;
}

/************************************************************************************************/

string Menu::getCharacterText(const Character &c) {

	stringstream text;
	text << BOLD_ON YELLOW << "*****CHARACTER******" << BOLD_OFF << std::endl << std::endl;
	text << BOLD_ON << "[Nom]: " << BLUE << c.getName() << BOLD_OFF << std::endl;
	text << BOLD_ON << "[Endurance]: " << c.getEP() << BOLD_OFF << "/" << BOLD_ON BLUE << c.getBaseEP() << BOLD_OFF << std::endl;
	text << BOLD_ON << "[Habilite]: " << c.getSP() << BOLD_OFF << "/" << BOLD_ON BLUE << c.getBaseSP() << BOLD_OFF << std::endl;
	text << BOLD_ON << "[Chance]: " << c.getLP() << BOLD_OFF << "/" << BOLD_ON BLUE << c.getBaseLP() << BOLD_OFF << std::endl;

	return text.str();
}

/************************************************************************************************/


string Menu::getInventoryText(const Character &c) {

	stringstream text;
	text << BOLD_ON YELLOW << "*****INVENTORY******" << BOLD_OFF << std::endl << std::endl;
	for (size_t i = 0; c._inventory.getItems(i).size(); i++)
		text << BOLD_ON BLUE << "[" << i << "]" << BOLD_OFF << ": " << BOLD_ON << c._inventory.getItems(i) << BOLD_OFF << std::endl;

	return text.str();
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

string Menu::getChapterText(const int chapter_no) {
	return (this->chapters[chapter_no - 1]);
}


string Menu::getText(string option, const Character &c) {
	int option_integer = atoi(option.c_str());
	
	if (option_integer >= 1 && option_integer <= 400) {
		return getChapterText(option_integer);
	} else if (option == "Display Inventory") {
		return getInventoryText(c);
	} else if (option == "Display Character") {
		return getCharacterText(c);
	} else { //Main Menu
		return "";
	}
}

void Menu::displayMenu(const Character &c, const string &location, const string& text) {
	size_t selectedIndex = 0;
	char input = 0;

	const vector<string> &options = this->menu_options[location];
	configureTerminal(true); // Passe en mode non canonique
	while (true) {
		clearConsole();
		if (location == "Main Menu")
			std::cout << "*****Menu*****\n\n";

		std::cout << text << std::endl;

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

	string next_menu = options[selectedIndex];
	string next_text = getText(next_menu, c);
	this->displayMenu(c, next_menu, next_text);
	
}

/************************************************************************************************/
