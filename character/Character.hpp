/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:08:10 by cyferrei          #+#    #+#             */
/*   Updated: 2024/11/26 15:25:00 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../colors.hpp"

#include "Inventory.hpp"

#include <string>
#include <iostream>

#define BASE_EP 12
#define BASE_SP 6
#define BASE_LP 6

class Character {
	private:
		std::string _name;
		unsigned int _EP;
		unsigned int _SP;
		unsigned int _LP;
		unsigned int _baseEP;
		unsigned int _baseSP;
		unsigned int _baseLP;
	public:
		Inventory _inventory;
		
		Character();
		Character(std::string const name, unsigned int EP, unsigned int SP, unsigned int LP);
		Character(const Character &other);
		Character &operator=(const Character &other);
		~Character();

		std::string getName(void)const;
		unsigned int getEP(void)const;
		unsigned int getSP(void)const;
		unsigned int getLP(void)const;
		unsigned int getBaseEP(void)const;
		unsigned int getBaseSP(void)const;
		unsigned int getBaseLP(void)const;

		void setName(std::string name);
		void setEP(unsigned int amount);
		void setSP(unsigned int amount);
		void setLP(unsigned int amount);
		void setBaseEP(unsigned int amount);
		void setBaseSP(unsigned int amount);
		void setBaseLP(unsigned int amount);

};

std::ostream &operator<<(std::ostream &out, const Character &character);
unsigned int rollDice(void);