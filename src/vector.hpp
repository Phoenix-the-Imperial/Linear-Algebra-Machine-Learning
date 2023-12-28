#ifndef INCLUDE_HPP
#define INCLUDE_HPP

#include <include.hpp>

namespace ML
{
    template <T>
    T vector_dot(std::vector<T> u, std::vector<T> v)
    {
        size_t d;
        if (u.length() < v.length()) d = u.length();
        else d = v.length();
        T ret = 0;
        for (size_t j = 0; j < d; j++)
            ret += u[j] * std::conj(v[j]);
        return ret;
    }
    template <T>
    class matrix
    {
        private:
            size_t num_rows;
            size_t num_cols;
            std::vector<std::vector<T>> rows;
        matrix();
        ~matrix();
    }

    matrix::matrix(size_t num_row, size_t num_col, ...)
    {
        
    }
}
#endif
