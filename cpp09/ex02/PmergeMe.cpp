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

PmergeMe::PmergeMe(char *argv[]) : AB_start(std::clock())
{  
    if (!valid_int(argv))
    {
        old_AB = AB;
        merge(AB);
    }
    else
        std::cerr << "[-] You entered an invalid input" << std::endl;
}

PmergeMe::~PmergeMe()
{
    // std::cout << "Before: " << 
    // for (size_t i = 0; i < AB.size() ; i++)
    //     std::cout << AB[i] << " ";
    print_nums(1);
    print_nums(0);
    AB_end = clock();
    std::cout << static_cast<double>(AB_end - AB_start) << std::endl;
}

void PmergeMe::print_nums(int first)
{
    std::vector<int>    current;
    if (first)
    {
        std::cout << "Before:   ";
        current = old_AB;
    }
    else
    {
        std::cout << "After:    ";
        current = AB;
    }
    size_t vec_size = current.size();
    if (vec_size < 6)
    {
        for (size_t i = 0; i < vec_size ; i++)
            std::cout << current[i] << " ";
    }
    else
    {
        for (size_t i = 0; i < 4 ; i++)
            std::cout << current[i] << " ";
        std::cout << "[...]";
    }
    std::cout << std::endl;
}

void    PmergeMe::merge_s(std::vector<int> &A, std::vector<int> &L, std::vector<int> &R)
{
    int i, j, k;

    i = j = k = 0;
    int nR = R.size();
    int nL = L.size();
    while(i < nL && j < nR)
    {
        if (L[i] < R[j])
            A[k] = L[i++];
        else
            A[k] = R[j++];
        k++;
    }
    while(i < nL)
        A[k++] = L[i++];

    while(j < nR)
        A[k++] = R[j++];
}

void    PmergeMe::merge(std::vector<int> &A)
{
    size_t n = A.size();
    if (n < 2)
        return ;
    std::vector<int> L(A.begin(), A.begin() + n/2);
    std::vector<int> R(A.begin() + n/2, A.end());
    merge(L);
    merge(R);
    merge_s(A, L, R);
}