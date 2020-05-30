/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: excalibur <excalibur@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 18:52:25 by excalibur         #+#    #+#             */
/*   Updated: 2020/05/30 00:52:29 by excalibur        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HPP
# define TEST_HPP

# include <string>
# include <fstream>
# include <iostream>
# include <sys/stat.h> 
# include <sys/types.h> 

# define NORMAL "\033[0;37m"
# define UNDERLINE "\033[4m"
# define BOLD_RED "\033[1;31m"
# define BOLD_GREEN "\033[1;32m"

// Vectors:

#if VECTOR_ALL == 1
    void test_vector(void);
#endif

# endif