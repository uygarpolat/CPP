/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 20:50:43 by upolat            #+#    #+#             */
/*   Updated: 2024/11/26 01:09:43 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Ice : public AMateria {
    public:
        Ice();
        //Ice(const Ice &other);
        //Ice &operator=(const Ice &other);
        ~Ice();

        AMateria* clone() const override;
        void use(ICharacter& target) override;
    protected:
        // ...
};