/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonster.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:07:59 by cyferrei          #+#    #+#             */
/*   Updated: 2024/11/19 17:35:14 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "../colors.hpp"

class IMonster {
	protected:
		std::string const _name;
		unsigned int _endurancePoint;
		unsigned int _skillPoint;

	public:
		IMonster();
		void setEP(unsigned int amount);
		unsigned int getEP(const IMonster monster)const;
		void setSP(unsigned int amount);
		unsigned int getSP(const IMonster monster)const;
		virtual ~IMonster() {};
};