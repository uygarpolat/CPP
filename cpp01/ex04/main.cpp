/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 19:44:14 by upolat            #+#    #+#             */
/*   Updated: 2024/11/20 23:45:01 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

    std::string replace_content(std::string &content, std::string argv2, std::string argv3)
    {
        //std::size_t flag = 0;
        std::string revised_content;
        std::size_t start = 0;
        std::size_t end;
        
        while (1)
        {
            end = content.find(argv2, start);
            if (end == std::string::npos)
            {  
                end = content.length();
                revised_content.append(content.substr(start, end - start));
                std::cout << "Match not found" << std::endl;
                // flag = 1;
                break ;
            }
            std::cout << "Match found at: " << end << std::endl;
            revised_content.append(content.substr(start, end - start));
            revised_content.append(argv3);
            start = end + argv2.length();
        }
        return revised_content;
    }


int main(int argc, char **argv) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <input_filename> <to_be_replaced_string> <replacement_string>" << std::endl;
        return 1;
    }

    std::ifstream in(argv[1]);
    if (!in.is_open()) {
        std::cerr << "Error: Could not open input file " << argv[1] << std::endl;
        return 1;
    }

    std::string outputFilename = std::string(argv[1]) + ".replace";
    std::ofstream out(outputFilename);
    if (!out.is_open()) {
        std::cerr << "Error: Could not open output file " << outputFilename << std::endl;
        return 1;
    }
    
    std::ostringstream buffer;
    buffer << in.rdbuf();
    std::string file_content = buffer.str();
    std::string replaced_content = replace_content(file_content, argv[2], argv[3]);
    out << replaced_content;
    //out << file_content;

    std::cout << "File contents successfully written to " << outputFilename << std::endl;
    return 0;
}
