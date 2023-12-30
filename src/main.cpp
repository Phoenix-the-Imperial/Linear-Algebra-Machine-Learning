#include <iostream>
// include <linear_regression.hpp>
#include <matrix.hpp>
// #include <vector>
int main()
{
    // std::vector<std::vector<float>> v = {{1, 2, 3}, {1, 2}};
    // v.at(0).resize(4);
    // v.at(0).at(3) = 4;
    // std::cout << v.at(0).at(3) << std::endl;
    auto m = ML::matrix<float>({1, 2, 3, 4, 5, 6}, 2, 3);
    std::cout << m;
    return 0;
}
