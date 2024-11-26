/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:13:03 by cyferrei          #+#    #+#             */
/*   Updated: 2024/11/26 15:52:50 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <string>
#include <ctime>
#include <limits>


Character::Character() {
	std::string input_name;
	std::srand(std::time(0));
		
	setSP(rollDice() + BASE_SP);
	setBaseSP(getSP());
	setEP(rollDice() + rollDice() + BASE_EP);
	setBaseEP(getEP());
	setLP(rollDice() + BASE_LP);
	setBaseLP(getLP());

	std::cout << "Enter the character's name: ";
	while (input_name.size() == 0) {
		std::getline(std::cin, input_name);
		if (std::cin.eof())
			exit(1);
		if (input_name.size() == 0) {
			std::cout << "error! Retry :";
			std::cin.clear();
		}
	}
	setName(input_name);
	std::cout << BOLD_ON YELLOW << "Default (Character) constructor called!" << BOLD_OFF << std::endl;
}


Character::Character(const std::string name, unsigned int EP, unsigned int SP, unsigned int LP) : _name(name), _EP(EP), _SP(SP), _LP(LP), _baseEP(EP), _baseSP(SP), _baseLP(LP) {
	std::cout << BOLD_ON BLUE << "Custom (Character) constructor called!" << BOLD_OFF << std::endl;
}

Character::Character(const Character &other) {
	*this = other;
	std::cout << BOLD_ON YELLOW << "Copy (Character) constructor called!" << BOLD_OFF << std::endl;
}

Character &Character::operator=(const Character &other) {
	if (this != &other) {
		this->_name = other.getName();
		this->_EP = other.getEP();
		this->_SP = other.getEP();
		this->_baseEP = other.getBaseEP();
		this->_baseSP = other.getBaseSP();
		this->_baseLP = other.getBaseLP();
	}
	return (*this);
	std::cout << BOLD_ON YELLOW << "Copy (Character) assigment called!" << BOLD_OFF << std::endl;
}

Character::~Character() {
	std::cout << BOLD_ON RED << "Default (Character) destructor called!" << BOLD_OFF << std::endl;
}

/************************************************************************************************/

std::string Character::getName(void)const { return(this->_name); }

unsigned int Character::getEP(void)const { return(this->_EP); }

unsigned int Character::getSP(void)const { return(this->_SP); }

unsigned int Character::getLP(void)const { return(this->_LP); }

unsigned int Character::getBaseEP(void)const { return(this->_baseEP); }

unsigned int Character::getBaseSP(void)const { return(this->_baseSP); }

unsigned int Character::getBaseLP(void)const { return(this->_baseLP); }

void Character::setName(std::string name) { this->_name = name; }

void Character::setEP(unsigned int amount){ this->_EP = amount; }

void Character::setSP(unsigned int amount) { this->_SP = amount; }

void Character::setLP(unsigned int amount){ this->_LP = amount; }

void Character::setBaseEP(unsigned int amount) { this->_baseEP = amount; }

void Character::setBaseSP(unsigned int amount) { this->_baseSP = amount; }

void Character::setBaseLP(unsigned int amount) { this->_baseLP = amount; }

/************************************************************************************************/

std::ostream &operator<<(std::ostream &out, const Character &character) {
	out << BOLD_ON << "**********" << BOLD_OFF << std::endl;
	out << BOLD_ON << "name: " << BLUE << character.getName() << BOLD_OFF << "." << std::endl;
	out << BOLD_ON << "EP: " << BLUE << character.getEP() << BOLD_OFF << "." << std::endl;
	out << BOLD_ON << "SP: " << BLUE << character.getSP() << BOLD_OFF << "." << std::endl;
	out << BOLD_ON << "LP: " << BLUE << character.getLP() << BOLD_OFF << "." << std::endl;
	out << BOLD_ON << "baseEP: " << BLUE << character.getBaseEP() << BOLD_OFF << "." << std::endl;
	out << BOLD_ON << "baseSP: " << BLUE << character.getBaseSP() << BOLD_OFF << "." << std::endl;
	out << BOLD_ON << "baseLP: " << BLUE << character.getBaseLP() << BOLD_OFF << "." << std::endl;
	out << BOLD_ON << "gold: " << BLUE << character._inventory.getGold() << BOLD_OFF "." << std::endl;
	for (size_t i = 0; character._inventory.getItems(i).size(); i++)
		out << BOLD_ON BLUE << i << BOLD_OFF << ": " << character._inventory.getItems(i) << std::endl;
	out << BOLD_ON << "**********" << BOLD_OFF << std::endl;
	return (out);
}

/************************************************************************************************/

unsigned int rollDice(void) {
	return (std::rand() % 6 + 1);
}