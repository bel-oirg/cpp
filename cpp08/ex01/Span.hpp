#pragma once

#include <exception>
#include <vector>
#include <iostream>

class Span
{
    private:
        std::vector<int>    listed;
        unsigned int        list_size;

    public:
        //ORTHDX
        Span(); 
        Span(const Span &eq);
        Span &operator=(const Span &eq);
        ~Span();

        Span(unsigned int N);

        void    fastadd(std::vector<int>::iterator f_elem, std::vector<int>::iterator l_elem);
        void    addNumber(int num);
        int     shortestSpan();
        int     longestSpan();

        class out_of_range : public std::exception
        {
            public:
            virtual const char *what() const throw()
            {
                return ("[-] Out of range");
            }
        };

        class not_enough_nums : public std::exception
        {
            public:
            virtual const char *what() const throw()
            {
                return ("[-] The numbers are not enough, no span can be found");
            }
        };
};