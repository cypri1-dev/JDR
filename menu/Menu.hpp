/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Menu.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:59:49 by cyferrei          #+#    #+#             */
/*   Updated: 2024/11/22 13:20:54 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../colors.hpp"
#include <sstream>
#include <vector>
#include <termios.h>
#include <unistd.h>
#include <map>

#include "../character/Character.hpp"

using namespace std;

typedef enum { MAIN_MENU, CHARACTER_MENU, INVENTORY_MENU } e_menu;

class Menu {
	public:
		Menu();
		~Menu();

		int displayMenu(const Character &c, e_menu mode, const stringstream &text = stringstream()) const;
		void displayCharacter(const Character &c)const;
		void displayInventory(const Character &c)const;
		// void save();
		// void exitMenu;
	private:
		vector<vector<string>> menu_options;
		void clearConsole() const;
};
