/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:28:07 by upolat            #+#    #+#             */
/*   Updated: 2025/02/19 13:30:46 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon {
    private:
        std::string _type;
    public:
        Weapon(const std::string &type);
        ~Weapon();
        const std::string&  getType() const;
        void                setType(std::string type);
};

#endif