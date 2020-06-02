/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testVector.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: excalibur <excalibur@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 18:38:33 by excalibur         #+#    #+#             */
/*   Updated: 2020/06/02 23:21:44 by excalibur        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <vector>
# include "test.hpp"

# include "../vector.hpp"


#if VECTOR_DEFAULT_CONSTRUCTOR == 1
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
    const std::vector<T> & stl_vector,
    const ft::vector<T> & ft_vector)
{
    std::string stl_empty = ((stl_vector.empty() == 1) ? "true" : "false");
    size_t stl_size = stl_vector.size();
    size_t stl_max_size = stl_vector.max_size();
    size_t stl_capacity = stl_vector.capacity();

    #if VECTOR_FUNC_EMPTY == 1
        std::string ft_empty = ((ft_vector.empty() == 1) ? "true" : "false");
        bool empty = equalbool(ft_empty, stl_empty);
    #endif
    
    #if VECTOR_FUNC_SIZE == 1
        size_t ft_size = ft_vector.size();
        bool size = equalbool(ft_size, stl_size);
    #endif
    
    #if VECTOR_FUNC_MAX_SIZE == 1
        size_t ft_max_size = ft_vector.max_size();
        bool max_size = equalbool(ft_max_size, stl_max_size);
    #endif
    
    #if VECTOR_FUNC_CAPACITY == 1
        size_t ft_capacity = ft_vector.capacity();
        bool capacity = equalbool(ft_capacity, stl_capacity);
    #endif

    fs << "\n══════════════════════════════════════════════════════════════\n";
    fs << "Vectors attributes : ";
    fs << "After test : " << after_test_msg << std::endl;
    fs << "STL :" << std::endl;
    fs << "Empty       : " << stl_empty  << std::endl;
    fs << "Size        : " << stl_size  << std::endl;
    fs << "Max size    : " << stl_max_size  << std::endl;
    fs << "Capacity    : " << stl_capacity  << std::endl;

    fs << "Content     : [";
    
    typename std::vector<T>::const_iterator stl_it;
    for (stl_it = stl_vector.begin();  stl_it != stl_vector.end(); stl_it++)
    {
        fs << *stl_it;
        if (stl_it + 1 != stl_vector.end())
            fs << ", ";
    }
    fs << "]\n";

    fs << std::endl;
    fs << "FT :" << std::endl;

    #if VECTOR_FUNC_EMPTY == 1
        fs << "Empty    [" << equal(ft_empty, stl_empty) << "]: " << ft_empty  << std::endl;
    #endif
    
    #if VECTOR_FUNC_SIZE == 1
        fs << "Size     [" << equal(ft_size, stl_size) << "]: " << ft_size  << std::endl;
    #endif
    
    #if VECTOR_FUNC_MAX_SIZE == 1
        fs << "Max size [" << equal(ft_max_size, stl_max_size) << "]: " << ft_max_size  << std::endl;
    #endif
    
    #if VECTOR_FUNC_CAPACITY == 1
        fs << "Capacity [" << equal(ft_capacity, stl_capacity) << "]: " << ft_capacity  << std::endl;
    #endif

    (void)ft_vector;
    // ft::vector<T> to_noc = ft_vector;
    // typename ft::vector<T>::iterator ft_it;
    // for(ft_it = to_noc.begin(); ft_it != to_noc.end(); ft_it++)
    // {
    //     fs << *ft_it;
    //     if (ft_it + 1 != to_noc.end())
    //         fs << ", ";
    // }
    // fs << "]\n";

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

// t1 == stl
// t2 == ft
template<class T>
static bool printVectorSingleValue(std::fstream& fs, const std::string& from, const T& t1, const T& t2)
{
    fs << "\n══════════════════════════════════════════════════════════════\n";
    fs << "Value from : " << from << " :\n";
    fs << "STL    : " << t1 << "\n";
    fs << "FT  [" << equal(t1, t2) << "]: " << t2 << "\n";
    fs << "\n══════════════════════════════════════════════════════════════\n";
    return (t1 == t2 ? true : false);
}


static void test_VectorCreation(void)
{
    std::fstream fs;
    
    #if VECTOR_CONSTRUCTOR_ALL == 1
        std::cout << "Constructors : ";

        #if VECTOR_DEFAULT_CONSTRUCTOR == 1
            std::vector<int> stl_default_vector;
            ft::vector<int> ft_default_vector;

            fs.open("vectors/default_constructor", std::fstream::in | std::fstream::out | std::fstream::trunc);
            std::cout << ((printVectorAttributes(fs, "Default Constructor", stl_default_vector, ft_default_vector) == true) ? "[OK]" : "[NOP]");
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "ft::vector<int> ft_default_vector;\n";
            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "std::vector<int> stl_default_vector;\n";
            fs.close();

            std::vector<int> *stl_pointer_default_vector = new std::vector<int>;
            ft::vector<int> *ft_pointer_default_vector = new ft::vector<int>;

            fs.open("vectors/pointer_default_constructor", std::fstream::in | std::fstream::out | std::fstream::trunc);
            std::cout << ((printVectorAttributes(fs, "Pointer to Default Constructor", *stl_pointer_default_vector, *ft_pointer_default_vector) == true) ? "[OK]" : "[NOP]");
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "ft::vector<int> *ft_pointer_default_vector = new ft::vector<int>;\n";
            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "std::vector<int> *stl_pointer_default_vector = new std::vector<int>;\n";
            fs.close();

            delete stl_pointer_default_vector;

            #if VECTOR_DESTRUCTOR == 1
                delete ft_pointer_default_vector;
            #endif
        #endif

        #if VECTOR_FILL_CONSTRUCTOR == 1
            std::vector<int> stl_fill_vector(0);
            ft::vector<int> ft_fill_vector(0);

            fs.open("vectors/fill_constructor_empty", std::fstream::in | std::fstream::out | std::fstream::trunc);
            std::cout << ((printVectorAttributes(fs, "Fill Constructor Empty", stl_fill_vector, ft_fill_vector) == true) ? "[OK]" : "[NOP]");
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "ft::vector<int> ft_fill_vector(0);\n";
            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "std::vector<int> stl_fill_vector(0);\n";
            fs.close();

            std::vector<int> stl_fill_vector_sized(19);
            ft::vector<int> ft_fill_vector_sized(19);

            fs.open("vectors/fill_constructor_sized", std::fstream::in | std::fstream::out | std::fstream::trunc);
            std::cout << ((printVectorAttributes(fs, "Fill Constructor Sized", stl_fill_vector_sized, ft_fill_vector_sized) == true) ? "[OK]" : "[NOP]");
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "ft::vector<int> ft_fill_vector_sized(19);\n";
            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "std::vector<int> stl_fill_vector_sized(19);\n";
            fs.close();

        #endif

        std::cout << "\n";
    #endif

    #if VECTOR_INSERT_ALL == 1
        std::cout << "Insert : ";

        #if VECTOR_FILL_INSERT_FUNC == 1
            
            #if VECTOR_DEFAULT_CONSTRUCTOR == 1 && VECTOR_ITERATOR_ASSIGN_CONSTRUCTOR == 1 && VECTOR_FUNC_BEGIN == 1

                std::vector<int> stl_fill_insert;
                ft::vector<int> ft_fill_insert;

                fs.open("vectors/fill_insert_empty", std::fstream::in | std::fstream::out | std::fstream::trunc);
                
                std::vector<int>::iterator stl_fill_insert_it = stl_fill_insert.begin();
                ft::vector<int>::iterator ft_fill_insert_it = ft_fill_insert.begin();

                stl_fill_insert.insert(stl_fill_insert_it, 8, 42);
                ft_fill_insert.insert(ft_fill_insert_it, 8, 42);

                std::cout << ((printVectorAttributes(fs, "Insert (fill) from empty", stl_fill_insert, ft_fill_insert) == true) ? "[OK]" : "[NOP]");
                fs << "\nCode executed:\n";
                fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
                fs << "ft::vector<int> ft_fill_insert;\n";
                fs << "ft::vector<int>::iterator ft_fill_insert_it = ft_fill_insert.begin();\n";
                fs << "ft_fill_insert.insert(ft_fill_insert_it, 8, 42);\n";
                fs << "\nCompared with:\n";
                fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
                fs << "std::vector<int> stl_fill_insert;\n";
                fs << "std::vector<int>::iterator stl_fill_insert_it = stl_fill_insert.begin();\n";
                fs << "stl_fill_insert.insert(stl_fill_insert_it, 8, 42);\n";
                fs.close();
                
            #endif

            #if VECTOR_FILL_CONSTRUCTOR == 1 && VECTOR_ITERATOR_ALL == 1 && VECTOR_ITERATOR_ASSIGN_CONSTRUCTOR == 1 && (VECTOR_ITERATOR_OPE_PLUS_EQUAL == 1 || VECTOR_ITERATOR_INCREMENTATION_RIGHT == 1) && VECTOR_FUNC_BEGIN == 1
                
                fs.open("vectors/fill_insert_filled", std::fstream::in | std::fstream::out | std::fstream::trunc);
                
                std::vector<int> stl_fill_insert_filled(15, 42);
                ft::vector<int> ft_fill_insert_filled(15,42);
                
                std::cout << ((printVectorAttributes(fs, "Insert (fill) from filled", stl_fill_insert_filled, ft_fill_insert_filled) == true) ? "[OK]" : "[NOP]");
                
                std::vector<int>::iterator stl_fill_insert_filled_it = stl_fill_insert_filled.begin();
                ft::vector<int>::iterator ft_fill_insert_filled_it = ft_fill_insert_filled.begin();

                #if VECTOR_ITERATOR_ALL == 1 && VECTOR_ITERATOR_OPE_PLUS_EQUAL == 1
                    ft_fill_insert_filled_it += 12;
                    stl_fill_insert_filled_it += 12;

                #elif VECTOR_ITERATOR_INCREMENTATION_RIGHT == 1
                    for (int i = 0; i < 12; i++)
                    {
                        ft_fill_insert_filled_it++;
                        stl_fill_insert_filled_it++;
                    }
                #endif

                stl_fill_insert_filled.insert(stl_fill_insert_filled_it, 4, 1);
                ft_fill_insert_filled.insert(ft_fill_insert_filled_it, 4, 1);

                std::cout << ((printVectorAttributes(fs, "Insert (fill) from filled", stl_fill_insert_filled, ft_fill_insert_filled) == true) ? "[OK]" : "[NOP]");
                fs << "\nCode executed:\n";
                fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";

                fs << "ft::vector<int> ft_fill_insert_filled(15,42);\n";
                fs << "ft::vector<int>::iterator ft_fill_insert_filled_it = ft_fill_insert_filled.begin();\n";
                
                #if VECTOR_ITERATOR_ALL == 1 && VECTOR_ITERATOR_OPE_PLUS_EQUAL == 1
                    fs << "ft_fill_insert_filled_it += 12;\n";
                #elif VECTOR_ITERATOR_INCREMENTATION_RIGHT == 1
                    fs << "for (int i = 0; i < 12; i++)\n";
                    fs << "   ft_fill_insert_filled_it++;\n";
                #endif
                fs << "ft_fill_insert_filled.insert(ft_fill_insert_filled_it, 8, 1);\n";
                
                fs << "\nCompared with:\n";
                fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";

                fs << "std::vector<int> stl_fill_insert_filled(15,42);\n";
                fs << "std::vector<int>::iterator stl_fill_insert_filled_it = stl_fill_insert_filled.begin();\n";
                #if VECTOR_ITERATOR_ALL == 1 && VECTOR_ITERATOR_OPE_PLUS_EQUAL == 1
                    fs << "stl_fill_insert_filled_it += 12;\n";
                #elif VECTOR_ITERATOR_INCREMENTATION_RIGHT == 1
                    fs << "for (int i = 0; i < 12; i++)\n";
                    fs << "   stl_fill_insert_filled_it++;\n";
                #endif
                fs << "stl_fill_insert_filled.insert(stl_fill_insert_filled_it, 8, 1);\n";
                fs.close();

            #endif

            #if VECTOR_DEFAULT_CONSTRUCTOR == 1 && VECTOR_FUNC_PUSHBACK == 1 && VECTOR_ITERATOR_ASSIGN_CONSTRUCTOR == 1 && (VECTOR_ITERATOR_OPE_PLUS_EQUAL == 1 || VECTOR_ITERATOR_INCREMENTATION_RIGHT == 1) && VECTOR_FUNC_BEGIN == 1
                
                fs.open("vectors/fill_insert_pushback", std::fstream::in | std::fstream::out | std::fstream::trunc);
                
                std::vector<int> stl_fill_insert_pushback;
                ft::vector<int> ft_fill_insert_pushback;

                for (int n = 0; n < 15; n++)
                {
                    stl_fill_insert_pushback.push_back(42);
                    ft_fill_insert_pushback.push_back(42);
                }

                std::vector<int>::iterator stl_fill_insert_pushback_it = stl_fill_insert_pushback.begin();
                ft::vector<int>::iterator ft_fill_insert_pushback_it = ft_fill_insert_pushback.begin();

                #if VECTOR_ITERATOR_ALL == 1 && VECTOR_ITERATOR_OPE_PLUS_EQUAL == 1
                    ft_fill_insert_pushback_it += 12;
                    stl_fill_insert_pushback_it += 12;

                #elif VECTOR_ITERATOR_INCREMENTATION_RIGHT == 1
                    for (int i = 0; i < 12; i++)
                    {
                        ft_fill_insert_pushback_it++;
                        stl_fill_insert_pushback_it++;
                    }
                #endif

                stl_fill_insert_pushback.insert(stl_fill_insert_pushback_it, 4, 1);
                ft_fill_insert_pushback.insert(ft_fill_insert_pushback_it, 4, 1);

                std::cout << ((printVectorAttributes(fs, "Insert (fill) from pushbacked", stl_fill_insert_pushback, ft_fill_insert_pushback) == true) ? "[OK]" : "[NOP]");

                fs << "\nCode executed:\n";
                fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
                fs << "ft::vector<int> ft_fill_insert_pushback;\n";
                fs << "for (int n = 0; n < 15; n++)\n";
                fs << "     ft_fill_insert_pushback.push_back(42);\n";
                fs << "ft::vector<int>::iterator ft_fill_insert_pushback_it = ft_fill_insert_pushback.begin();\n";
                #if VECTOR_ITERATOR_ALL == 1 && VECTOR_ITERATOR_OPE_PLUS_EQUAL == 1
                    fs << "ft_fill_insert_pushback_it += 12;\n";
                #elif VECTOR_ITERATOR_INCREMENTATION_RIGHT == 1
                    fs << "for (int i = 0; i < 12; i++)\n";
                    fs << "   ft_fill_insert_pushback_it++;";
                #endif
                fs << "ft_fill_insert_pushback.insert(ft_fill_insert_pushback_it, 4, 1);\n";

                fs << "\nCompared with:\n";
                fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
                fs << "std::vector<int> stl_fill_insert_pushback;\n";
                fs << "for (int n = 0; n < 15; n++)\n";
                fs << "     stl_fill_insert_pushback.push_back(42);\n";
                fs << "std::vector<int>::iterator stl_fill_insert_pushback_it = stl_fill_insert_pushback.begin();\n";
                
                #if VECTOR_ITERATOR_ALL == 1 && VECTOR_ITERATOR_OPE_PLUS_EQUAL == 1
                    fs << "stl_fill_insert_pushback_it += 12;\n";
                #elif VECTOR_ITERATOR_INCREMENTATION_RIGHT == 1
                    fs << "for (int i = 0; i < 12; i++)\n";
                    fs << "   stl_fill_insert_pushback_it++;";
                #endif
                fs << "stl_fill_insert_pushback.insert(stl_fill_insert_pushback_it, 4, 1);\n";
                fs.close();
            #endif
            
            std::cout << "\n";
        #endif
    #endif
}

void test_vector(void)
{
    std::cout << UNDERLINE << "VECTORS :\n" << NORMAL ;

    mkdir("vectors", 0777);
    
    test_VectorCreation();
}
#endif