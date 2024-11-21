/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Inventory.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:58:51 by cyferrei          #+#    #+#             */
/*   Updated: 2024/11/21 15:10:00 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Inventory.hpp"

Inventory::Inventory() {
	this->_gold = 0;
	std::cout << BOLD_ON YELLOW << "Default (Inventory) constructor called!" << BOLD_OFF << std::endl;
}

Inventory::Inventory(const Inventory &other) {
	this->_gold = other.getGold();
	for (int i = 0; i < 100; i++)
		this->_items[i] = other.getItems(i);
	std::cout << BOLD_ON YELLOW << "Copy (Inventory) constructor called!" << BOLD_OFF << std::endl;
}

Inventory &Inventory::operator=(const Inventory &other) {
	if (this != &other)
	{
		this->_gold = other.getGold();
		for (int i = 0; i < 100; i++)
			this->_items[i] = other.getItems(i);
	}
	return (*this);
	std::cout << BOLD_ON YELLOW << "Copy (Inventory) assigment called!" << BOLD_OFF << std::endl;

}

Inventory::~Inventory() {
	std::cout << BOLD_ON RED << "Default (Inventory) destructor called!" << BOLD_OFF << std::endl;
}

/************************************************************************************************/

unsigned int Inventory::getGold(void)const { return this->_gold; }

std::string Inventory::getItems(unsigned int idx)const { return this->_items[idx]; }

void Inventory::setGold(unsigned int amount) { this->_gold += amount; }

void Inventory::setItems(unsigned int idx, std::string const item) {this->_items[idx] = item; }

/************************************************************************************************/

