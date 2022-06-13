#include <iostream>
using namespace std;
template <typename elemType>
class Matrix
{
    //类模板中友函数声明要为模板函数，注意不要用和Matrix的模板参数名称一样的模板参数名
    template <typename T>
    friend Matrix<T> operator+(const Matrix<T>&, const Matrix<T>&);
    template <typename T>
    friend Matrix<T> operator*(const Matrix<T>&, const Matrix<T>&);

public:
    Matrix(int rows, int columns)
        : _rows(rows), _cols(columns)
    {
        int size = _rows * _cols;
        _matrix = new elemType[size];
        for(int i = 0; i < size; i++)
            _matrix[i] = elemType();
    }
    Matrix(const Matrix&);
    ~Matrix() { delete []_matrix; }
    Matrix& operator=(const Matrix&);

    void operator+=(const Matrix&);
    elemType& operator()(int row, int column)
        { return _matrix[row*cols() + column]; }
    const elemType& operator()(int row, int column) const
        { return _matrix[row*cols() + column]; }

    int rows() const { return _rows; }
    int cols() const { return _cols; }

    bool same_size(const Matrix &m) const
        { return rows() == m.rows() && cols() == m.cols(); }
    bool comfortable(const Matrix &m) const
        { return (cols() == m.rows());}
    ostream& print(ostream&) const;

protected:
    int _rows;
    int _cols;
    elemType *_matrix;
};

template <typename elemType>
inline ostream& operator<<(ostream &os, const Matrix<elemType> &m)
    { return m.print(os); }

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