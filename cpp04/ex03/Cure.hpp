/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 21:11:44 by upolat            #+#    #+#             */
/*   Updated: 2024/11/26 01:09:48 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Cure : public AMateria {
    public:
        Cure();
        //Cure(const Cure &other);
        //Cure &operator=(const Cure &other);
        ~Cure();

        AMateria* clone() const override;
        void use(ICharacter& target) override;
    protected:
        // ...
};