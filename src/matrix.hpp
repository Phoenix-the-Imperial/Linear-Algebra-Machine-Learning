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
        matrix(const size_t&, const size_t&);
        matrix(void);

        T& at(const size_t&, const size_t&);
        T get_at(const size_t&, const size_t&) const;
        size_t num_row(void) const;
        size_t num_col(void) const;
        std::tuple<size_t, size_t> size(void);
        void reserve(const size_t&, const size_t&);
        void resize(const size_t&, const size_t&);
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
    matrix<T>::matrix(const size_t& num_row, const size_t& num_col)
    {
        this->resize(num_row, num_col);
    }

    template <class T>
    matrix<T>::matrix()
    {
        this->num_rows = 0;
        this->num_cols = 0;
        this->rows.resize(0);
    }

    // Do not use!
    template <class T>
    void matrix<T>::reserve(const size_t& num_row, const size_t& num_col)
    {
        this->rows.resize(num_row);
        for (size_t j = 0; j < num_row; j++)
            this->rows.at(j).reserve(num_col);
    }

    template <class T>
    void matrix<T>::resize(const size_t& num_row, const size_t& num_col)
    {
        this->rows.resize(num_row);
        for (size_t j = 0; j < num_row; j++)
            this->rows.at(j).resize(num_col);
        this->num_rows = num_row;
        this->num_cols = num_col;
    }

    template <class T>
    std::tuple<size_t, size_t> matrix<T>::size(void)
    {
        return std::tuple<size_t, size_t>(this->num_row(), this->num_col());
    }

    template <class T>
    T& matrix<T>::at(const size_t& row, const size_t& col)
    {
        // Check if row and col are in range
        return this->rows.at(row).at(col);
    }

    template <class T>
    T matrix<T>::get_at(const size_t& row, const size_t& col) const
    {
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
                output_stream << m.get_at(j, k) << '\t';
            }
            output_stream << m.get_at(j, num_col - 1) << '\n';
        }
        return output_stream;
    }

    template <class T>
    matrix<T> multiply(const matrix<T>& a, const matrix<T>& b)
    {
        size_t r = a.num_row();
        size_t p = a.num_col();
        size_t c = b.num_col();
        // Check if the matrices are compatible
        matrix<T> ret = matrix<T>(r, c);
        T sum = (T) 0;
        size_t j, k, l;
        for (j = 0; j < r; j++)
        {
            for (k = 0; k < c; k++)
            {
                for (l = 0; l < p; l++)
                    sum += a.get_at(j, l) * b.get_at(l, k);
                ret.at(j, k) = sum;
                sum = 0;
            }
        }
        return ret;
    }

    template <class U, class T>
    matrix<T> multiply(const U& scalar, const matrix<T>& a)
    {
        T s = T(scalar);
        size_t m = a.num_row();
        size_t n = a.num_col();
        matrix<T> ret = matrix<T>(m, n);
        size_t j, k;
        for (j = 0; j < m; j++)
            for (k = 0; k < n; k++)
                ret.at(j, k) = s * a.get_at(j, k);
        return ret;
    }

    template <class T>
    matrix<T> hadamard_product(const matrix<T>& a, const matrix<T>& b)
    {
        size_t m = a.num_row();
        size_t n = a.num_col();
        // Check if the matrices are compatible
        matrix<T> ret = matrix<T>(m, n);
        size_t j, k;
        for (j = 0; j < m; j++)
            for (k = 0; k < n; k++)
                ret.at(j, k) = a.get_at(j, k) * b.get_at(j, k);
        return ret;
    }

    template <class T>
    matrix<T> add(const matrix<T>& a, const matrix<T>& b)
    {
        size_t m = a.num_row();
        size_t n = a.num_col();
        // Check if the matrices are compatible
        matrix<T> ret = matrix<T>(m, n);
        size_t j, k;
        for (j = 0; j < m; j++)
            for (k = 0; k < n; k++)
                ret.at(j, k) = a.get_at(j, k) + b.get_at(j, k);
        return ret;
    }

    template <class U, class T>
    matrix<T> add(const U& scalar, const matrix<T>& a)
    {
        T s = T(scalar);
        size_t m = a.num_row();
        size_t n = a.num_col();
        matrix<T> ret = matrix<T>(m, n);
        size_t j, k;
        for (j = 0; j < m; j++)
            for (k = 0; k < n; k++)
                ret.at(j, k) = s + a.get_at(j, k);
        return ret;
    }

    template <class T>
    matrix<T> transpose(const matrix<T>& m)
    {
        size_t r = m.num_row();
        size_t c = m.num_col();
        matrix<T> ret = matrix<T>(c, r);
        size_t j, k;
        for (j = 0; j < r; j++)
            for (k = 0; k < c; k++)
                ret.at(k, j) = m.get_at(j, k);
        return ret;
    }

    template <class T>
    matrix<T> zeros(const size_t& m, const size_t& n)
    {
        matrix<T> ret = matrix<T>(m, n);
        size_t j, k;
        for (j = 0; j < m; j++)
            for (k = 0; k < n; k++)
                ret.at(j, k) = 0;
        return ret;
    }


    template <class T>
    matrix<T> ones(const size_t& m, const size_t& n)
    {
        matrix<T> ret = matrix<T>(m, n);
        size_t j, k;
        for (j = 0; j < m; j++)
            for (k = 0; k < n; k++)
                ret.at(j, k) = 1;
        return ret;
    }

    template <class T>
    std::tuple<matrix<T>, matrix<T>> LU_Doolittle(const matrix<T>& A)
    {
        // Check if the argument matrix is diagonal
        size_t n = A.num_col();
        matrix<T> L = matrix<T>(n, n);
        matrix<T> U = matrix<T>(n, n);
        size_t i, j, k;
        T sum;
        for (k = 0; k < n; k++)
        {
            L.at(k, k) = 1;
            for (j = k; j < n; j++)
            {
                sum = 0;
                for (i = 0; i < k; i++)
                    sum += L.get_at(k, i) * U.get_at(i, j);
                U.at(k, j) = A.get_at(k, j) - sum;
            }
            for (j = k + 1; j < n; j++)
            {
                sum = 0;
                for (i = 0; i < k; i++)
                    sum += L.get_at(j, i) * U.get_at(i, k);
                L.at(j, k) = (A.get_at(j, k) - sum) / U.get_at(k, k);
            }
        }
        std::tuple<matrix<T>, matrix<T>> ret = std::tuple<matrix<T>, matrix<T>>(L, U);
        return ret;
    }
}
#endif
