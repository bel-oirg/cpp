#pragma once

#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
#include <vector>

class PmergeMe
{
    private:
        std::vector<int>    AB;

    public:
        void    merge_s(std::vector<int> A, std::vector<int> L, std::vector<int> R);
        void    merge(std::vector<int> &A);
        int     valid_int(char *argv[]);
        int     atoii(char *arg);
        PmergeMe(char *argv[]);
        PmergeMe();
        ~PmergeMe();
};