/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:13:03 by cyferrei          #+#    #+#             */
/*   Updated: 2024/11/21 15:31:24 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("default"), _EP(0), _SP(0), _LP(0) , _baseEP(0), _baseSP(0), _baseLP(0) {
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
	if (this != &other)
	{
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

void Character::setEP(unsigned int amount) { this->_EP = amount; }

void Character::setSP(unsigned int amount) { this->_SP = amount; }

void Character::setBaseEP(unsigned int amount) { this->_EP = amount; }

void Character::setBaseSP(unsigned int amount) { this->_SP = amount; }

void Character::setBaseLP(unsigned int amount) { this->_LP = amount; }

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