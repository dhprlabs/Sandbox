#include <iostream>
#include "dhpr_vector/dhpr_vector.hpp"

int main() 
{
    dhpr::vector<int> v;

    for (int i = 0; i < 10; ++i)
        v.push_back(i);

    for (size_t i = 0; i < v.size(); ++i)
        std::cout << v[i] << " ";
}
