#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <include.hpp>

namespace ML
{
    template <class T>
    T vector_dot(std::vector<T> u, std::vector<T> v)
    {
        size_t d;
        if (u.length() < v.length()) d = u.length();
        else d = v.length();
        T ret = 0;
        for (size_t j = 0; j < d; j++)
            ret += u.at(j) * std::conj(v.at(j));
        return ret;
    }
    template <class T>
    class matrix
    {
        private:
            size_t num_rows;
            size_t num_cols;
            std::vector<std::vector<T>> rows;
        public:
        matrix(std::initializer_list<T>, const size_t&, const size_t&);

        T& at(const size_t&, const size_t&);
        size_t num_row(void) const;
        size_t num_col(void) const;
    };

    template <class T>
    matrix<T>::matrix(std::initializer_list<T> elements, const size_t& num_row, const size_t& num_col)
    { 
        this->rows.resize(num_row);
        size_t j = 0, k = 0;
        for (auto elem : elements)
        {
            this->rows.at(j).resize(num_col);
            this->rows.at(j).at(k) = elem;
            k++;
            if (k == num_col)
            {
                k = 0;
                j++;
            }
            if (j == num_row) break;
        }
        this->num_rows = num_row;
        this->num_cols = num_col;
    }

    template <class T>
    T& matrix<T>::at(const size_t& row, const size_t& col)
    {
        // Check if row and col are in range
        return this->rows.at(row).at(col);
    }

    template <class T>
    size_t matrix<T>::num_row() const
    {
        return this->num_rows;
    }

    template <class T>
    size_t matrix<T>::num_col() const
    {
        return this->num_cols;
    }

    template<class T>
    std::ostream& operator <<(std::ostream& output_stream, matrix<T>& m)
    {
        size_t num_row = m.num_row();
        size_t num_col = m.num_col();
        size_t j, k;
        for (j = 0; j < num_row; j++)
        {
            for (k = 0; k < num_col - 1; k++)
            {
                output_stream << m.at(j, k) << '\t';
            }
            output_stream << m.at(j, num_col - 1) << '\n';
        }
        return output_stream;
    }
}
#endif
