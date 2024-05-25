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
        matrix(const std::vector<T>&);
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
        matrix<T> get_row(const size_t&) const;
        matrix<T> get_col(const size_t&) const;
        void set_row(const size_t&, const matrix<T>&);
        void set_col(const size_t&, const matrix<T>&);
    };


    template <class T>
    matrix<T>::matrix(const std::vector<T>& v)
    {
        size_t n = v.size();
        this->resize(n, 1);
        for (size_t i = 0; i < n; i++)
            this->at(i, 0) = v.at(i);
    }

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
    matrix<T> matrix<T>::get_row(const size_t& row) const
    {
        matrix<T> ret = matrix<T>(1, this->num_cols);
        for (size_t k = 0; k < this->num_cols; k++)
            ret.at(0, k) = this->get_at(row, k);
        return ret;
    }

    template <class T>
    matrix<T> matrix<T>::get_col(const size_t& col) const
    {
        matrix<T> ret = matrix<T>(this->num_rows, 1);
        for (size_t j = 0; j < this->num_rows; j++)
            ret.at(j, 0) = this->get_at(j, col);
        return ret;
    }

    template <class T>
    void matrix<T>::set_row(const size_t& row, const matrix<T>& row_vector)
    {
        // Check if the matrix and the row vector are compatible
        for (size_t k = 0; k < this->num_cols; k++)
            this->at(row, k) = row_vector.get_at(0, k);
    }

    template <class T>
    void matrix<T>::set_col(const size_t& col, const matrix<T>& col_vector)
    {
        // Check if the matrix and the row vector are compatible
        for (size_t j = 0; j < this->num_rows; j++)
            this->at(j, col) = col_vector.get_at(j, 0);
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

    template <class T>
    matrix<T> operator *(const matrix<T>& a, const matrix<T>& b)
    {
        return multiply(a, b);
    }

    template <class T>
    matrix<T> multiply(const matrix<T>& a, const std::vector<T>& v)
    {
        size_t r = a.num_row();
        size_t c = a.num_col();
        // Check if the matrix and the vector are compatible
        matrix<T> ret = matrix<T>(r, 1);
        T sum = (T) 0;
        size_t j, k;
        for (j = 0; j < r; j++)
        {
            for (k = 0; k < c; k++)
                sum += a.get_at(j, k) * v.at(k);
            ret.at(j, 0) = sum;
            sum = 0;
        }
        return ret;
    }

    template <class T>
    matrix<T> operator *(const matrix<T>& a, const std::vector<T>& b)
    {
        return multiply(a, b);
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

    template <class U, class T>
    matrix<T> operator *(const U& scalar, const matrix<T>& a)
    {
        return multiply(scalar, a);
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
    matrix<T> hadamard_division(const matrix<T>& a, const matrix<T>& b)
    {
        size_t m = a.num_row();
        size_t n = a.num_col();
        // Check if the matrices are compatible
        matrix<T> ret = matrix<T>(m, n);
        size_t j, k;
        for (j = 0; j < m; j++)
            for (k = 0; k < n; k++)
                // Check if divisor is non-zero
                ret.at(j, k) = a.get_at(j, k) / b.get_at(j, k);
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

    template <class T>
    matrix<T> operator +(const matrix<T>& a, const matrix<T>& b)
    {
        return add(a, b);
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

    template <class U, class T>
    matrix<T> operator +(const U& scalar, const matrix<T>& a)
    {
        return add(scalar, a);
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

    template <class T>
    matrix<T> solve_back_substitution(const matrix<T>& A, const matrix<T>& b)
    {
        size_t n = A.num_col();
        // Check if b has same number of rows
        size_t i, j, k;
        T sum;
        matrix<T> x = matrix<T>(n, 1);
        for (i = 0; i < n; i++)
        {
            j = n - 1 - i;
            sum = 0;
            for (k = j + 1; k < n; k++)
                sum += A.get_at(j, k) * x.get_at(k, 0);
            x.at(j, 0) = (b.get_at(j, 0) - sum) / A.get_at(j, j);
        }
        return x;
    }

    template <class T>
    matrix<T> solve_forward_substitution(const matrix<T>& A, const matrix<T>& b)
    {
        size_t n = A.num_col();
        // Check if b has same number of rows
        size_t j, k;
        T sum;
        matrix<T> x = matrix<T>(n, 1);
        for (j = 0; j < n; j++)
        {
            sum = 0;
            for (k = 0; k < j; k++)
                sum += A.get_at(j, k) * x.get_at(k, 0);
            x.at(j, 0) = (b.get_at(j, 0) - sum) / A.get_at(j, j);
        }
        return x;
    }

    template <class T>
    matrix<T> LU_solve(const matrix<T>& A, const matrix<T>& b)
    {
        std::tuple<matrix<T>, matrix<T>> LU_decomposition = LU_Doolittle(A);
        matrix<T> L = std::get<0>(LU_decomposition);
        matrix<T> U = std::get<1>(LU_decomposition);
        // Solve L(Ux) = b for (Ux).
        matrix<T> x_intermediate = solve_forward_substitution(L, b);
        // Solve Ux = b for x.
        matrix<T> x = solve_back_substitution(U, x_intermediate);
        return x;
    }

    template <class T>
    matrix<T> LU_solve(const matrix<T>& L, const matrix<T> U, const matrix<T>& b)
    {
        // Solve L(Ux) = b for (Ux).
        matrix<T> x_intermediate = solve_forward_substitution(L, b);
        // Solve Ux = b for x.
        matrix<T> x = solve_back_substitution(U, x_intermediate);
        return x;
    }

    template <class T>
    matrix<T> LU_inverse(const matrix<T>& A)
    {
        size_t r = A.num_row();
        size_t c = A.num_col();
        // Check if A is square
        matrix<T> ret = matrix<T>(r, c);
        matrix<T> solved_col = matrix<T>(r, 1);
        matrix<T> identity_col = zeros<T>(r, 1);
        // Store the LU decomposition of the matrix A
        std::tuple<matrix<T>, matrix<T>> LU = LU_Doolittle(A);
        matrix<T> L = std::get<0>(LU);
        matrix<T> U = std::get<1>(LU);
        size_t k;
        for (k = 0; k < c; k++)
        {
            identity_col.at(k, 0) = 1;
            if (k > 0) identity_col.at(k - 1, 0) = 0;
            solved_col = LU_solve(L, U, identity_col);
            ret.set_col(k, solved_col);
        }
        return ret;
    }

    // The Moore-Penrose inverse of a matrix
    template <class T>
    matrix<T> pseudo_inverse(const matrix<T>& A)
    {
        return multiply(LU_inverse(multiply(transpose(A), A)), transpose(A));
    }
}
#endif
