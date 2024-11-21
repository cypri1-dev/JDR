/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Monsters.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:37:14 by cyferrei          #+#    #+#             */
/*   Updated: 2024/11/21 11:33:51 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../colors.hpp"

#include <string>
#include <iostream>

class Monsters {
	private:
		std::string _name;
		unsigned int _EP;
		unsigned int _SP;
	public:
		Monsters();
		Monsters(const std::string name, unsigned int EP, unsigned int SP);
		Monsters(const Monsters &other);
		Monsters &operator=(const Monsters &other);
		~Monsters();
		
		std::string getName(void)const;
		unsigned int getEP(void)const;
		unsigned int getSP(void)const;

		void setName(std::string name);
		void setEP(unsigned int amount);
		void setSP(unsigned int amount);
};

std::ostream &operator<<(std::ostream &out, const Monsters &m);