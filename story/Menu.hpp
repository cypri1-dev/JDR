/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Menu.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:59:49 by cyferrei          #+#    #+#             */
/*   Updated: 2024/11/26 14:29:58 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../colors.hpp"
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <termios.h>
#include <unistd.h>

#include "../character/Character.hpp"

#define BOOK_PATH "story/parsed_chapters.json"
using namespace std;

class Menu {
	public:
		Menu();
		~Menu();

		void displayMenu(const Character &c, const string &location, const string &text = "");
		string getChapterText(const int chapter_no);
		string getInventoryText(const Character &c);
		string getCharacterText(const Character &c);
		string getText(string option, const Character &c);
		void addMenuOptions(...);
		// void save();
		// void exitMenu;
	private:
		unordered_map<string, vector<string>> menu_options;
		void clearConsole() const;
		vector<string> chapters; // struct for chapters
};
