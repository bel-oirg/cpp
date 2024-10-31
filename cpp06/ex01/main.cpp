#include "Serializer.hpp"

int main()
{
    Data a;

    a._int = 14;
    uintptr_t out = Serializer::serialize(&a);
    std::cout << "serialized " << out << std::endl;
    std::cout << "deserialized int " << Serializer::deserialize(out)->_int << std::endl;
}