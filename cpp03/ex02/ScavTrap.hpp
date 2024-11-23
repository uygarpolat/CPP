/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:51:51 by upolat            #+#    #+#             */
/*   Updated: 2024/11/23 20:28:11 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
    public:
        ScavTrap();
        ScavTrap(const ScavTrap &other);
        ScavTrap &operator=(const ScavTrap &other);
        ~ScavTrap();
        ScavTrap(const std::string name);

        void attack(const std::string& target);
        void guardGate();
};