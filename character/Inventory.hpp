/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Inventory.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:53:00 by cyferrei          #+#    #+#             */
/*   Updated: 2024/11/21 13:16:05 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../colors.hpp"

#include <string>
#include <iostream>

class Inventory {
	private:
		std::string _items[100];
		unsigned int _gold;
	public:
		Inventory();
		Inventory(const Inventory &other);
		Inventory &operator=(const Inventory &other);
		~Inventory();

		unsigned int getGold(void)const;
		std::string getItems(unsigned int idx)const;

		void setGold(unsigned int amount);
		void setItems(unsigned int idx, std::string const item);
};