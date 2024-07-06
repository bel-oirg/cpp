#include <iostream>

class Zombie
{
    private:
    std::string name;

    public:
    Zombie(std::string name) : name(name) {}
    ~Zombie();
    void    annouce(void);
    void    randomChump(std::string name);
    Zombie *newZombie(std::string name);
};