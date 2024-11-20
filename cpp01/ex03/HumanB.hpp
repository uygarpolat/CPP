/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:41:43 by upolat            #+#    #+#             */
/*   Updated: 2024/11/20 19:34:41 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
    public:
        HumanB(const std::string &name);
        ~HumanB();
        void attack() const;
        void setWeapon(Weapon &weapon);
    private:
        std::string _name;
        Weapon *_weaponOfB;
};

#endif