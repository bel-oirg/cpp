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
        CD.push_back(val);
    }
    return (0);
}

PmergeMe::PmergeMe(char *argv[]) : stat(0)
{  
    if (!valid_int(argv))
    {
        old_AB = AB;

        start = std::clock();
        vectored(AB);
        AB_end = clock();
        dequed(CD);
        CD_end = clock();
        stat = 1;
    }
    else
        std::cerr << "[-] You entered an invalid input" << std::endl;
}

PmergeMe::~PmergeMe()
{
    if (stat)
    {
        print_nums(1);
        print_nums(0);
        std::cout << "Time to process a range of "<< AB.size() << " elements with std::vector : " << static_cast<double>(AB_end - start) << " us" << std::endl;
        std::cout << "Time to process a range of "<< AB.size() << " elements with std::deque  : " << static_cast<double>(CD_end - start) << " us" << std::endl;
    }
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

void    PmergeMe::merge_vector(std::vector<int> &A, std::vector<int> &L, std::vector<int> &R)
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

void    PmergeMe::vectored(std::vector<int> &A)
{
    size_t n = A.size();
    if (n < 2)
        return ;
    std::vector<int> L(A.begin(), A.begin() + n/2);
    std::vector<int> R(A.begin() + n/2, A.end());
    vectored(L);
    vectored(R);
    merge_vector(A, L, R);
}


void    PmergeMe::dequed(std::deque<int> &A)
{
    size_t n = A.size();
    if (n < 2)
        return ;
    std::deque<int> L(A.begin(), A.begin() + n/2);
    std::deque<int> R(A.begin() + n/2, A.end());
    dequed(L);
    dequed(R);
    merge_deque(A, L, R);
}

void    PmergeMe::merge_deque(std::deque<int> &A, std::deque<int> &L, std::deque<int> &R)
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
