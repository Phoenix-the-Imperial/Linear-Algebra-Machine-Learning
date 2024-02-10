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
    std::vector<float> v = {0, 1, 2};
    auto R = ML::matrix<float>(v);
    std::cout << "\n\n" << R;
    auto S = ML::multiply<float>(O_dot_dot, v);
    std::cout << "\n\n" << S;
    auto x = ML::solve_back_substitution<float>(U, R);
    std::cout << "\n\n" << x;
    auto R_dot = ML::multiply(U, x);
    std::cout << "\n\n" << R_dot;
    auto y = ML::solve_forward_substitution<float>(L, R);
    std::cout << "\n\n" << y;
    auto R_dot_dot = ML::multiply(L, y);
    std::cout << "\n\n" << R_dot_dot;
    auto X = ML::LU_solve(M, R);
    std::cout << "\n\n" << X;
    auto R_prime = ML::multiply(M, X);
    std::cout << "\n\n" << R_prime;
    auto T_r = M.get_row(1);
    auto T_c = M.get_col(1);
    std::cout << "\n\n" << T_r << "\n\n" << T_c;
    auto r_vect = ML::matrix<float>({7, -7, 42}, 1, 3);
    auto c_vect = ML::matrix<float>({15, 72}, 2, 1);
    O_dot_dot.set_row(1, r_vect);
    std::cout << "\n\n" << O_dot_dot;
    O_dot_dot.set_col(0, c_vect);
    std::cout << "\n\n" << O_dot_dot;
    auto M_inverse = ML::LU_inverse(M);
    std::cout << "\n\n" << M_inverse;
    auto I_check = ML::multiply(M, M_inverse);
    std::cout << "\n\n" << I_check;
    return 0;
}
