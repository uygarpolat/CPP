/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:00:18 by upolat            #+#    #+#             */
/*   Updated: 2025/02/19 13:30:21 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
    public:
        HumanA(const std::string &name, Weapon &weapon);
        ~HumanA();
        void attack() const;
    private:
        std::string _name;
        Weapon &_weaponOfA;
};

#endif