#include "Matrix.h"
template<typename elemType>
Matrix<elemType>::Matrix(const Matrix &rhs)
{
    _rows = rhs._rows; _cols = rhs._cols;
    int mat_size = _rows*_cols;
    _matrix = new elemType[mat_size];
    for (int i = 0; i < mat_size; ++i)
        _matrix[i] = rhs._matrix[i];
}

template<typename elemType>
Matrix<elemType>& Matrix<elemType>::operator=(const Matrix &rhs)
{
    if (this != &rhs) {
        _rows = rhs._rows; _cols = rhs._cols;
        int mat_size = _rows*_cols;
        delete []_matrix;
        _matrix = new elemType[mat_size];
        for (int i = 0; i < mat_size; ++i)
            _matrix[i] = rhs._matrix[i];
    }
    return *this;
}

template<typename elemType>
Matrix<elemType>
operator+(const Matrix<elemType> &m1, const Matrix<elemType> &m2)
{   
    Matrix<elemType> result(m1);
    result += m2;
    return result;
}


template<typename elemType>
Matrix<elemType>
operator*(const Matrix<elemType> &m1, const Matrix<elemType> &m2)
{
    Matrix<elemType> result( m1.rows(),m2.cols());
    for (int i = 0; i < m1.rows(); i++) {
        for (int j = 0; j < m2.cols(); j++) {
            result(i, j) = 0;
            for (int k = 0; k < m1.cols(); k++) {
                result(i, j) += m1(i, k) * m2(k, j);
            }
        }
    }
    return result;

}

template <typename elemType>
void Matrix<elemType>::operator+=( const Matrix &m )
{
    // 确定ml和 m2的大小相同
    int matrix_size = cols()*rows();
    for(int ix=0;ix<matrix_size;++ix)
        (*( _matrix+ ix))+=(*(m._matrix+ ix));
}

template <typename elemType>
ostream& Matrix<elemType>::print( ostream &os) const
{
    int col = cols();
    int matrix_size = col*rows();
    for(int ix= 0;ix< matrix_size;++ix ){
        if(ix % col == 0)os << endl;
        os << (*(_matrix+ ix)) << ' ';
    }
    os << endl;
    return os;
}