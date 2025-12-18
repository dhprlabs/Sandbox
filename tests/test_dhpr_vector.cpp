#include <iostream>
#include "dhpr_vector/dhpr_vector.hpp"

int main() 
{
    dhpr::vector<int> v;

    for (int i = 0; i < 10; ++i)
        v.push_back(i);

    for (size_t i = 0; i < v.size(); ++i)
        std::cout << v[i] << " ";

    dhpr::vector<int> d(v);

    for (size_t i = 0; i < d.size(); ++i)
        std::cout << d[i] << " ";

    dhpr::vector<int> f;
    f.push_back(3);
    f.push_back(5);

    dhpr::vector<int> g;
    g = f;
}
