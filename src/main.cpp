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
    auto n = ML::matrix<float>({1, 0, 0, 1, 1, 0}, 3, 2);
    //auto b = ML::matrix<float>(1, 3);
    //for (size_t j = 0; j < 3; j++)
    //    b.at(0, j) = j + 1;
    auto a = ML::multiply<float>(m, n);
    //n.resize(2, 1);
    std::cout << m << "\n\n" << n << "\n\n" << a;
    //std::cout << b;
    return 0;
}
