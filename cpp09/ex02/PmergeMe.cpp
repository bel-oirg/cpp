#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

int PmergeMe::atoii(char *arg)
{
    unsigned int res = 0;
    int index = 0;
    while(arg[index] >= '0' && arg[index] <= '9')
    {
        res = res * 10 + arg[index++] - '0';
        if (res > INT_MAX)
            return (-1);
    }
    if (arg[index])
        return (-1);
    return (static_cast<int>(res));
}

int PmergeMe::valid_int(char *argv[])
{
    int index = -1;

    while(argv[++index])
    {
        int val = atoii(argv[index]);
        if (val < 0)
            return (-1);
        AB.push_back(val);
    }
    return (0);
}

PmergeMe::PmergeMe(char *argv[])
{  
    if (!valid_int(argv))
    {
        std::vector<int> B = AB;
        merge(B);
        for (size_t i = 0; i < B.size() ; i++)
            std::cout << B[i] << std::endl;
    }
    else
        std::cerr << "[-] You entered an invalid input" << std::endl;
}

PmergeMe::~PmergeMe() {}

void    PmergeMe::merge_s(std::vector<int> A, std::vector<int> L, std::vector<int> R)
{
    int i, j, k;

    i = j = k = 0;
    int nR = R.size();
    int nL = L.size();
    while(i < nL && j < nL)
    {
        if (L[i] < R[j])
            A[k] = L[i++];
        else
            A[k] = R[j++];
        k++;
    }
    while(i < nL)
        A[k] = L[i++];

    while(j < nR)
        A[k] = R[j++];
}

void    PmergeMe::merge(std::vector<int> &A)
{
    size_t n = A.size();
    if (n < 2)
        return ;
    std::vector<int>    L;
    std::vector<int>    R;
    for (size_t index = 0; index < n/2 ; index++)
        L.push_back(A[index]);
    for (size_t index = n/2 ; index < n ; index++)
        R.push_back(A[index]);
    merge(L);
    merge(R);
    merge_s(A, L, R);
}