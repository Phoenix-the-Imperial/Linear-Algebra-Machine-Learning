#include <iostream>
// include <linear_regression.hpp>
#include <matrix.hpp>

int main()
{
    auto m = ML::matrix({1, 2, 3, 4, 5, 6}, 2, 3);
    std::cout << m;
    return 0;
}
