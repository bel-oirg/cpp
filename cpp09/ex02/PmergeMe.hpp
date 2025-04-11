#pragma once

#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <ctime>
#include <deque>
#include <algorithm>
#include <climits>

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
        void    vectored(std::vector<int> &A);

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

        template <typename T>
        void sort_pairs(T &nums, int pair_lvl);

};

/*
    check if all err used on std::cerr
*/

size_t jacob_num(size_t n);


template <typename T>
bool _cmp(T x, T y)
{
    return (*x < *y);
}

template <typename T>
T adv(T it, int pos)
{
    std::advance(it, pos);
    return it;
}

template <typename T>
void swaped(T left, T right)
{
    T bkp = left;
    while(bkp != right)
        std::iter_swap(left--, right--);
}

template <typename T>
void PmergeMe::sort_pairs(T &nums, int pair_lvl)
{
    typedef typename T::iterator it_p;
    typedef typename std::vector<it_p>::iterator vit;

    int pair_tile = nums.size() / pair_lvl;
    if (pair_tile < 2)
        return;

    bool is_odd = pair_tile % 2;

    it_p last = adv(nums.begin(),pair_lvl * pair_tile);
    it_p end = adv(last, -is_odd * pair_lvl);

    for (it_p it = nums.begin(); it != end; it += 2*pair_lvl)
    {
        it_p this_p = adv(it, pair_lvl - 1);
        it_p next_p = adv(it, pair_lvl * 2 - 1);
        if (_cmp(next_p, this_p))
            swaped(this_p, next_p);
    }
    sort_pairs(nums, pair_lvl * 2);


    std::vector<it_p> main;
    std::vector<it_p> pend;

    main.insert(main.end(), adv(nums.begin(), pair_lvl - 1)); //b1
    main.insert(main.end(), adv(nums.begin(), 2*pair_lvl - 1)); //a1

    for (int i = 4; i <= pair_tile; i+=2)
    {
        main.insert(main.end(), adv(nums.begin(), pair_lvl * i - 1 )); //insert a2, a3 ..
        pend.insert(pend.end(), adv(nums.begin(), pair_lvl * (i - 1) - 1 )); //insert b2, b3...
    }
    if (is_odd)
        pend.insert(pend.end(), adv(end, pair_lvl - 1));
    

    int prev_j = jacob_num(1);
    int inserted_count = 0;
    for (int i = 2; ;i++)
    {
        int current_j = jacob_num(i);
        int diff_j = current_j - prev_j;
        if (diff_j > static_cast<int>(pend.size()))
            break;

        int count = diff_j;
        vit pend_it = pend.begin() + diff_j - 1;
        vit bound_it = main.begin() + current_j + inserted_count;

        while(count--)
        {
            vit index = std::upper_bound(main.begin(), bound_it, *pend_it, _cmp<it_p>);
            main.insert(index, *pend_it);
            pend_it = pend.erase(pend_it);
            std::advance(pend_it, -1);
            bound_it = main.begin() + current_j + inserted_count;
        }
        prev_j = current_j;
        inserted_count += diff_j;
    }


    size_t pend_sized = pend.size(); //check if pend not empty yet
    for (size_t i = 0; i < pend_sized ; i++)
    {
        vit curr_p = adv(pend.begin(), i);
        vit curr_b = adv(main.begin(), main.size() - pend_sized + i + is_odd);
        vit index = std::upper_bound(main.begin(), curr_b, *curr_p, _cmp<it_p>);
        main.insert(index, *curr_p);
    }

    std::vector<int> tmp_v;
    for (vit it = main.begin(); it != main.end(); it++)
    {
        for (int i = 0; i < pair_lvl; i++)
        {
            it_p pair_beg = *it;
            advance(pair_beg, -pair_lvl + i + 1);
            tmp_v.insert(tmp_v.end(), *pair_beg);
        }
    }

    //updating the original nums cont
    it_p nums_beg = nums.begin();
    std::vector<int>::iterator tmp_beg = tmp_v.begin();
    while(tmp_beg != tmp_v.end())
        *nums_beg++ = *tmp_beg++;

}