#pragma once

#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include <ctime>

class PmergeMe
{
    private:
        std::vector<int>    AB;
        std::vector<int>    old_AB;
        std::clock_t        start;
        std::clock_t        AB_end;
        std::clock_t        CD_end;
        int                 stat;
        std::deque<int>      CD;


    public:
        void    print_nums(int first);
        void    merge_vector(std::vector<int> &A, std::vector<int> &L, std::vector<int> &R);
        void    vectored(std::vector<int> &A);

        void    merge_deque(std::deque<int> &A, std::deque<int> &L, std::deque<int> &R);
        void    dequed(std::deque<int> &A);
        int     valid_int(char *argv[]);
        int     atoii(char *arg);
        PmergeMe(char *argv[]);
        PmergeMe();
        ~PmergeMe();
};