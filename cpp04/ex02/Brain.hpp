/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:18:04 by upolat            #+#    #+#             */
/*   Updated: 2024/11/25 15:24:51 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Brain {
    public:
        Brain();
        Brain(const Brain &other);
        Brain &operator=(const Brain &other);
        ~Brain();

        void setIdea(std::string const &ideaString);
        void getIdea(const unsigned int ideaNumber) const;
        void getIdeas() const;
    protected:
        std::string ideas[100];
        unsigned int _ideaCounter;
};