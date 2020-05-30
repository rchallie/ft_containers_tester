/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: excalibur <excalibur@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 22:20:09 by excalibur         #+#    #+#             */
/*   Updated: 2020/05/30 00:52:04 by excalibur        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <vector>
# include <iostream>

# include "test.hpp"

#if VECTOR_ALL == 1
    # include "../vector.hpp"
#endif

void printTitle(void)
{
    std::cout << "   ___ _                      _        _                     \n";
    std::cout << "  / __\\ |_     ___ ___  _ __ | |_ __ _(_)_ __   ___ _ __ ___ \n";
    std::cout << " / _\\ | __|   / __/ _ \\| '_ \\| __/ _` | | '_ \\ / _ \\ '__/ __|\n";
    std::cout << "/ /   | |_   | (_| (_) | | | | || (_| | | | | |  __/ |  \\__ \\\n";
    std::cout << "\\/     \\__|___\\___\\___/|_| |_|\\__\\__,_|_|_| |_|\\___|_|  |___/\n";
    std::cout << "         |_____|                                             \n";
    std::cout << "Tester by rchallie.";
    std::cout << "\n══════════════════════════════════════════════════════════════\n\n";
}

int main()
{
    printTitle();

#if VECTOR_ALL == 1
    test_vector();
#endif

    return (0);
}