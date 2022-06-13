#include <iostream>
using namespace std;
template <typename elemType>
class Matrix
{
    friend Matrix<elemType> operator+(const Matrix<elemType>&, const Matrix<elemType>&);
    friend Matrix<elemType> operator*(const Matrix<elemType>&, const Matrix<elemType>&);

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
inline ostream& 
operator<< (ostream &os, const Matrix<elemType> &m)
    { return m.print(os); }