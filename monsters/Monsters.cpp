/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Monsters.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:30:11 by cyferrei          #+#    #+#             */
/*   Updated: 2024/11/21 11:05:57 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Monsters.hpp"

Monsters::Monsters() : _name("default"), _EP(0), _SP(0) {
	std::cout << BOLD_ON YELLOW << "Default (Monsters) constructor called!" << BOLD_OFF << std::endl;
}

Monsters::Monsters(const std::string name, unsigned int EP, unsigned int SP) : _name(name), _EP(EP), _SP(SP) {
	std::cout << BOLD_ON BLUE << "Custom (Monsters) constructor called!" << BOLD_OFF << std::endl;
}

Monsters::Monsters(const Monsters &other) {
	*this = other;
	std::cout << BOLD_ON YELLOW << "Copy (Monsters) constructor called!" << BOLD_OFF << std::endl;
}

Monsters &Monsters::operator=(const Monsters &other) {
	if (this != &other)
	{
		this->_name = other.getName();
		this->_EP = other.getEP();
		this->_SP = other.getEP();
	}
	return (*this);
}

Monsters::~Monsters() {
	std::cout << BOLD_ON RED << "Default (Monsters) destructor called!" << BOLD_OFF << std::endl;
}

/************************************************************************************************/

std::string Monsters::getName(void)const { return(this->_name); }

unsigned int Monsters::getEP(void)const { return(this->_EP); }

unsigned int Monsters::getSP(void)const { return(this->_SP); }

void Monsters::setName(std::string name) { this->_name = name; }

void Monsters::setEP(unsigned int amount) { this->_EP = amount; }

void Monsters::setSP(unsigned int amount) { this->_SP = amount; }

/************************************************************************************************/
