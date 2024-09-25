/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_test.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:27:17 by upolat            #+#    #+#             */
/*   Updated: 2024/09/10 16:38:49 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <chrono>
#include <iomanip>
#include <ctime>

void get_time(int flag)
{
    // Get current time
    auto now = std::chrono::system_clock::now();

    // Convert to time_t, which represents the time in seconds since epoch
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

    // Convert to tm structure for local time
    std::tm *localTime = std::localtime(&currentTime);

    // Print the date and time in the desired format
	if (flag == 1)
		std::cout << "[" 
				<< std::put_time(localTime, "%Y%m%d_%H%M%S")
				<< "] ";
	else
		std::cout << "[19920104_091532] ";
}

int	main(void)
{
	get_time(1);
	return (0);
}

