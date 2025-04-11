#include "PmergeMe.hpp"

int PmergeMe::atoii(char *arg)
{
    unsigned int res = 0;
    int index = 0;
    if (!arg[index])
        return (-1);
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

int PmergeMe::valid_int_vec(char *argv[])
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

int PmergeMe::valid_int_deq(char *argv[])
{
    int index = -1;

    while(argv[++index])
    {
        int val = atoii(argv[index]);
        if (val < 0)
            return (-1);
        CD.push_back(val);
    }
    return (0);
}

int    PmergeMe::sort_vector(char *argv[])
{
    AB_start = std::clock();
    if (valid_int_vec(argv) < 0)
    {
        std::cerr << "[-] You entered an invalid input" << std::endl;
        return (-1);
    }
    unsorted = AB;
    vectored(AB);
    AB_end = clock();
    stat = 1;
    return (0);
}

int    PmergeMe::sort_deque(char *argv[])
{
    CD_start = std::clock();
    if (valid_int_deq(argv) < 0)
    {
        std::cerr << "[-] You entered an invalid input" << std::endl;
        return (-1);
    }
    dequed(CD);
    CD_end = clock();
    stat = 1;
    return (0);
}

PmergeMe::PmergeMe(char *argv[]) : stat(0)
{
    sort_vector(argv);
    if (stat) //if the first sort_vectors did not failed
        sort_deque(argv);        
}

void PmergeMe::print_nums(int first)
{
    std::vector<int>    current;
    if (first)
    {
        std::cout << "Before:   ";
        current = unsorted;
    }
    else
    {
        std::cout << "After:    ";
        current = AB;
    }
    size_t vec_size = current.size();
    for (size_t i = 0; i < vec_size ; i++)
        std::cout << current[i] << " ";
    std::cout << std::endl;
}

void    PmergeMe::vectored(std::vector<int> &A)
{
    size_t n = A.size();
    if (n < 2)
        return ;

    sort_pairs(A, 1);
}

void    PmergeMe::dequed(std::deque<int> &A)
{
    size_t n = A.size();
    if (n < 2)
        return ;

    sort_pairs(A, 1);
}

//ORTHDX

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &cpy)
{
    *this = cpy;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &cpy)
{
    this->stat = cpy.stat;
    this->AB_start = cpy.AB_start;
    this->CD_start = cpy.CD_start;
    this->AB_end = cpy.AB_end;
    this->CD_end = cpy.CD_end;
    this->AB = cpy.AB;
    this->unsorted = cpy.unsorted;
    this->CD = cpy.CD;
    return (*this);
}

PmergeMe::~PmergeMe()
{
    if (stat)
    {
        print_nums(1);
        print_nums(0);
        std::cout << "Time to process a range of "<< AB.size() << " elements with std::vector : " << static_cast<double>(AB_end - AB_start) << " us" << std::endl;
        std::cout << "Time to process a range of "<< AB.size() << " elements with std::deque  : " << static_cast<double>(CD_end - AB_end) << " us" << std::endl;
    }
}

size_t jacob_num(size_t n)
{
    if (n < 2)
        return n;
    return (jacob_num(n - 1) + 2 * jacob_num(n - 2));
}