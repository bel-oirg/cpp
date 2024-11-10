#include "Span.hpp"

Span::Span() : list_size(0) {}

Span &Span::operator=(const Span &eq)
{
    this->list_size = eq.list_size;
    this->listed = eq.listed;
    return (*this);
}

Span::Span(const Span &eq)
{
    this->list_size = eq.list_size;
    this->listed = eq.listed;
}

Span::~Span() {}

Span::Span(unsigned int N) : list_size(N) {}

void Span::fastadd(std::vector<int>::iterator f_elem, std::vector<int>::iterator l_elem)
{
    if (listed.size() + std::distance(f_elem, l_elem) > list_size)
        throw out_of_range();
    
    listed.insert(listed.end(), f_elem, l_elem);
}

void Span::addNumber(int num)
{
    if (listed.size() >= list_size)
        throw out_of_range();
    listed.push_back(num);
}

int Span::shortestSpan()
{
    if (listed.size() < 2)
        throw not_enough_nums();

    std::vector<int> cpy = this->listed;
    std::sort(cpy.begin(), cpy.end());
    int min = cpy[1] - cpy[0];
    unsigned int _size_ = cpy.size() - 1;
    for (unsigned int index = 1; index < _size_; index++)
    {
        int spaned = cpy[index + 1] - cpy[index];
        if (spaned < min)
            min = spaned;
    }
    return (min);
}

int Span::longestSpan()
{
    if (listed.size() < 2)
        throw not_enough_nums();
    return (*std::max_element(listed.begin(), listed.end()) - *std::min_element(listed.begin(), listed.end()));
}

/*
    -------###### VECTOR
    is a dynamic array, if the alloc space is insufficient,
    it reallocate a larger block and copying the elemts to the new one
    and freeing the old mem
    - it uses one block of mem

    O(1) for random access 
    O(n) for insertion/deletion at beginning/middle
    O(1) for insertion/deletion at the end, but if no reallocation needed

    use vec.capacity() to check the allocated elems.

    Best use: storing games scores, list of products in a store.

    -------###### DEQUE
    is double ended queue uses an array of ptrs to multiple smaller
    memory blocks, each block can store a fixed number of elems
    the array called "map"

    std::deque<int> dq = { 1, 2, 3, 4, 5 };
    Map (array of pointers to blocks):
    ----------------------------------------------------------------------
    | [Pointer to Block 1] | [Pointer to Block 2] | [Pointer to Block 3] |
    ----------------------------------------------------------------------

    Block 1: [1, 2]
    Block 2: [3, 4]
    Block 3: [5]

    O(1) for random access (a lil slower than vector)
    O(1) for insertion/deletion at beginning/end
    O(n) for insertion/deletion middle

    can be used for: browsing history..

    -------###### LIST
    doubly lnkd list, each elem is stored in a separate node
    with pointer to prev and next node.
    nodes are dynamically allocated, and not stored continiously.

    O(n) for random access
    O(1) for insertion/deletion
*/