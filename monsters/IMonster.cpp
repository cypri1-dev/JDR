/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonster.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:14:24 by cyferrei          #+#    #+#             */
/*   Updated: 2024/11/19 17:35:35 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMonster.hpp"

IMonster::IMonster() {
	std::cout << BOLD_ON GREEN << "Default (IMonster) constructor called!" << BOLD_OFF << std::endl;
}

unsigned int IMonster::getEP(const IMonster monster)const {
	return (this->_endurancePoint);
}

unsigned int IMonster::getSP(const IMonster monster)const {
	return (this->_skillPoint);
}

void IMonster::setEP(unsigned int amount) {
	this->_endurancePoint = amount;
}

void IMonster::setSP(unsigned int amount) {
	this->_skillPoint = amount;
}