/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testVector.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: excalibur <excalibur@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 18:38:33 by excalibur         #+#    #+#             */
/*   Updated: 2020/05/30 16:26:43 by excalibur        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <vector>
# include "test.hpp"

// #if VECTOR_ALL == 1

# include "../vector.hpp"

template <class T>
bool equalbool(const T& t1, const T& t2)
{
    return (t1 == t2 ? true : false);
}

template <class T>
std::string equal(const T& t1, const T& t2)
{
    return (t1 == t2 ? "✔" : "✘");
}

template <class T>
bool printVectorAttributes(
    std::fstream& fs,
    const std::string & after_test_msg, 
    const std::vector<T> & std_vector,
    const ft::vector<T> & ft_vector)
{
    std::string std_empty = ((std_vector.empty() == 1) ? "true" : "false");
    size_t std_size = std_vector.size();
    size_t std_max_size = std_vector.max_size();
    size_t std_capacity = std_vector.capacity();

    #if VECTOR_FUNC_EMPTY == 1
        std::string ft_empty = ((ft_vector.empty() == 1) ? "true" : "false");
        bool empty = equalbool(ft_empty, std_empty);
    #endif
    
    #if VECTOR_FUNC_SIZE == 1
        size_t ft_size = ft_vector.size();
        bool size = equalbool(ft_size, std_size);
    #endif
    
    #if VECTOR_FUNC_MAX_SIZE == 1
        size_t ft_max_size = ft_vector.max_size();
        bool max_size = equalbool(ft_max_size, std_max_size);
    #endif
    
    #if VECTOR_FUNC_CAPACITY == 1
        size_t ft_capacity = ft_vector.capacity();
        bool capacity = equalbool(ft_capacity, std_capacity);
    #endif

    fs << "\n══════════════════════════════════════════════════════════════\n";
    fs << "Vectors attributes : ";
    fs << "After test : " << after_test_msg << std::endl;
    fs << "STD :" << std::endl;
    fs << "Empty       : " << std_empty  << std::endl;
    fs << "Size        : " << std_size  << std::endl;
    fs << "Max size    : " << std_max_size  << std::endl;
    fs << "Capacity    : " << std_capacity  << std::endl;
    fs << std::endl;
    fs << "FT :" << std::endl;

    #if VECTOR_FUNC_EMPTY == 1
        fs << "Empty    [" << equal(ft_empty, std_empty) << "]: " << ft_empty  << std::endl;
    #endif
    
    #if VECTOR_FUNC_SIZE == 1
        fs << "Size     [" << equal(ft_size, std_size) << "]: " << ft_size  << std::endl;
    #endif
    
    #if VECTOR_FUNC_MAX_SIZE == 1
        fs << "Max size [" << equal(ft_max_size, std_max_size) << "]: " << ft_max_size  << std::endl;
    #endif
    
    #if VECTOR_FUNC_CAPACITY == 1
        fs << "Capacity [" << equal(ft_capacity, std_capacity) << "]: " << ft_capacity  << std::endl;
    #endif
    fs << "══════════════════════════════════════════════════════════════\n";

    #if VECTOR_FUNC_EMPTY == 1
        if (empty == false)
            return (false);
    #endif
    
    #if VECTOR_FUNC_SIZE == 1
        if (size == false)
            return (false);
    #endif 

    #if VECTOR_FUNC_MAX_SIZE == 1
        if (max_size == false)
            return (false);
    #endif
    
    #if VECTOR_FUNC_CAPACITY == 1
        if (capacity == false)
            return (false);
    #endif
    return (true);
}

// static void test_VectorPushBack(void)
// {
//     std::vector<int> std_push_vector;
//     ft::vector<int> ft_push_vector;

//     std_push_vector.push_back(2);
//     ft_push_vector.push_back(2);

//     std_push_vector.push_back(5);
//     ft_push_vector.push_back(5);

//     std_push_vector.push_back(8);
//     ft_push_vector.push_back(8);

//     std_push_vector.push_back(15);
//     ft_push_vector.push_back(15);

//     std_push_vector.push_back(18);
//     ft_push_vector.push_back(18);


//     std_push_vector.push_back(42);
//     ft_push_vector.push_back(42);

//     std::vector<int>::iterator test = std_push_vector.begin();
//     std::cout << "Test end = " << *test  << std::endl;

//     ft::vector<int>::iterator test2 = ft_push_vector.begin();
 
//     std::cout << *test2 << std::endl;
//     ++test2;
//     ++test2;
//     test2++;
//     *test2++;
//     std::cout << *test2 << std::endl;
//     std::cout << *(test2 + 1) << std::endl;
//     std::cout << "Actual : " << *(1 + test2) << std::endl;
//     ft::vector<int>::iterator plop2 = (test2 - 1);
//     std::cout << *plop2 << std::endl;
//     int meh2 = (test2 - plop2);
//     std::cout << meh2 << std::endl;

//     std::cout << std::endl;
//     std::cout << *test << std::endl;
//     ++test;
//     ++test;
//     test++;
//     *test++;
//     std::cout << *test << std::endl;
//     std::cout << *(test + 1) << std::endl;
//     std::cout << "Actual : " << *(1 + test) << std::endl;
//     std::vector<int>::iterator plop = (test - 1);
//     std::cout << *plop << std::endl;
//     int meh = (test - plop);
//     std::cout << meh << std::endl;
//     std::cout << std::endl;

//     if (test2[0] == test[0])
//         std::cout << "EQUAL" << std::endl;
//     else
//         std::cout << "NOT EQUAL" << std::endl;

//     if (test < plop)
//     std::cout << "MEH" << std::endl;
//     else
//     std::cout << "PLOP" << std::endl;

//     if (test2 < plop2)
//     std::cout << "MEH2" << std::endl;
//     else
//     std::cout << "PLOP2" << std::endl;

//     if (test > plop)
//         std::cout << "MEH" << std::endl;
//     else
//         std::cout << "PLOP" << std::endl;

//     if (test2 > plop2)
//         std::cout << "MEH2" << std::endl;
//     else
//         std::cout << "PLOP2" << std::endl;

//     int vneorjvre = test[-2];
//     std::cout << vneorjvre << std::endl;

//     int vneorjvre2 = test2[-2];
//     std::cout << vneorjvre2 << std::endl;

//     vneorjvre -= 2;
//     std::cout << vneorjvre << std::endl;

//     vneorjvre2 -= 2;
//     std::cout << vneorjvre2 << std::endl;


//     printVectorAttributes("Push back", std_push_vector, ft_push_vector);
// }

static void test_VectorCreation(void)
{
    std::fstream fs;
    
    std::cout << "Construct : ";

    // Empty Constructor
    std::vector<int> std_empty_vector;
    ft::vector<int> ft_empty_vector;

    fs.open("vectors/empty_creation", std::fstream::in | std::fstream::out | std::fstream::trunc);
    std::cout << ((printVectorAttributes(fs, "Empty Constructor", std_empty_vector, ft_empty_vector) == true) ? "[OK]" : "[NOP]"); 
    fs.close();

    std::vector<int> *std_pointer_empty_vector = new std::vector<int>;
    ft::vector<int> *ft_pointer_empty_vector = new ft::vector<int>;

    fs.open("vectors/pointer_empty_creation", std::fstream::in | std::fstream::out | std::fstream::trunc);
    std::cout << ((printVectorAttributes(fs, "Pointer to Empty Constructor", *std_pointer_empty_vector, *ft_pointer_empty_vector) == true) ? "[OK]" : "[NOP]"); 
    fs.close();
}

void test_vector(void)
{
    std::cout << UNDERLINE << "VECTORS :\n" << NORMAL ;

    mkdir("vectors", 0777);
    
    test_VectorCreation();
    // test_VectorPushBack();
}
// #endif