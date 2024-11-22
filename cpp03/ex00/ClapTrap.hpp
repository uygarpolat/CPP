/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 01:17:08 by upolat            #+#    #+#             */
/*   Updated: 2024/11/23 01:32:39 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>

class ClapTrap {
    public:
        ClapTrap();
        ClapTrap(const ClapTrap &other);
        ClapTrap &operator=(const ClapTrap &other);
        ~ClapTrap();

        ClapTrap(std::string);
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
    private:
        std::string _name;
        int _hitPoints;
        int _energyPoints;
        int _attackDamage;
};

#endif