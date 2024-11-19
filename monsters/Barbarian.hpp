/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Barbarian.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:37:14 by cyferrei          #+#    #+#             */
/*   Updated: 2024/11/19 17:39:36 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IMonster.hpp"
#include <string>
#include <iostream>

class Barbarian : public IMonster {
	public:
		Barbarian();
		Barbarian(const std::string name, unsigned int EP, unsigned int SP);
		Barbarian(const Barbarian &other);
		Barbarian &operator=(const Barbarian &other);
		~Barbarian();
};