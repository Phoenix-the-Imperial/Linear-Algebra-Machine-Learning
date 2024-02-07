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
    auto b = ML::transpose(a);
    //n.resize(2, 1);
    std::cout << m << "\n\n" << n << "\n\n" << a << "\n\n" << b;
    //std::cout << b;
    /*
    auto c = a;
    c.at(1, 1) += 1;
    std::cout << "\n\n" << a << "\n\n" << c;
    */
    auto N = ML::matrix<float>({4, 3, 6, 3}, 2, 2);
    auto M = ML::matrix<float>({1, 2, 3, 1, 4, 9, 1, 8, 27}, 3, 3);
    auto LU = ML::LU_Doolittle(M);
    auto L = std::get<0>(LU);
    auto U = std::get<1>(LU);
    auto M_dot = ML::multiply(L, U);
    std::cout << "\n\n" << M << "\n\n" << L << "\n\n" << U << "\n\n" << M_dot;
    auto Z = ML::zeros<float>(3, 2);
    auto O = ML::ones<float>(2, 3);
    std::cout << "\n\n" << Z << "\n\n" << O;
    auto O_dot = ML::multiply(7, O);
    std::cout << "\n\n" << O_dot;
    auto O_dot_dot = ML::add(1, O_dot);
    std::cout << "\n\n" << O_dot_dot;
    auto P = ML::add(O_dot_dot, O);
    std::cout << "\n\n" << P;
    auto Q = ML::hadamard_product(P, O_dot_dot);
    std::cout << "\n\n" << Q;
    return 0;
}
