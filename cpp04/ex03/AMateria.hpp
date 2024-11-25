/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 20:45:07 by upolat            #+#    #+#             */
/*   Updated: 2024/11/26 01:08:39 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include "ICharacter.hpp"

class AMateria {
    public:
        AMateria();
        //AMateria(const AMateria &other);
        //AMateria &operator=(const AMateria &other);
        virtual ~AMateria();

        AMateria(const std::string  &type); // Parametrized constructor
        //...
        std::string const & getType() const; //Returns the materia type
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
    protected:
        std::string const _type;
};