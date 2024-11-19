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
        int                 stat;
        std::clock_t        AB_start;
        std::clock_t        CD_start;
        std::clock_t        AB_end;
        std::clock_t        CD_end;
        std::vector<int>    AB;
        std::deque<int>     CD;
        std::vector<int>    unsorted;

    public:
        void    merge_vector(std::vector<int> &A, std::vector<int> &L, std::vector<int> &R);
        void    vectored(std::vector<int> &A);

        void    merge_deque(std::deque<int> &A, std::deque<int> &L, std::deque<int> &R);
        void    dequed(std::deque<int> &A);

        int    sort_vector(char *argv[]);
        int    sort_deque(char *argv[]);

        void    print_nums(int first);
        int     valid_int_vec(char *argv[]);
        int     valid_int_deq(char *argv[]);
        int     atoii(char *arg);
        PmergeMe(char *argv[]);

        //ORTHDX
        PmergeMe();
        PmergeMe(const PmergeMe &cpy);
        PmergeMe &operator=(const PmergeMe &cpy);
        ~PmergeMe();
};

/*
    check if all err used on std::cerr
*/