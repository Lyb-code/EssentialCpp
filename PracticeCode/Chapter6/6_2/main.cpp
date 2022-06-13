#include<iostream>
#include<fstream>
#include "Matrix.h"
using namespace std;

int main()
{
    ofstream log("..\\log.txt");
    if(!log)
    {
        cerr << "can't open log file!\n";
        return 0;
    }

    Matrix<float> identity(4, 4);
    cout << "identity: " << identity << endl;
    float ar[16] = {1., 0., 0., 0., 0., 1., 0., 0.,
                    0., 0., 1., 0., 0., 0., 0., 1. };

    for(int i = 0, k = 0; i < 4; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            identity(i, j) = ar[k++];
        }
    }
    cout << "identity after set: " << identity << endl;

    Matrix<float> m(identity);
    cout << "m: memberwise initialized: " << m << endl;

    Matrix<float> m2(8, 12);
    cout << "m2: 8x12: " << m2 << endl;

    m2 = m;
    cout << "m2 after memberwise assigned to m: " << m2 << endl;

    float ar2[16] = {1.3, 0.4, 2.6, 8.2, 6.2, 1.7, 1.3, 8.3,
                     4.2, 7.4, 2.7, 1.9, 6.3, 8.1, 5.6, 6.6 };

    Matrix<float> m3(4,4);
    for(int i = 0, k = 0; i < 4; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            m3(i, j) = ar2[k++];
        }
    }
    cout << "m3: assigned random values: " << m3 << endl;

    Matrix<float> m4 = m3*identity;
    cout << "result of m3*identity: " << m4 << endl;

    Matrix<float> m5 = m3 + m4;
    cout << "result of m3 + m4: " << m5 << endl;

    m3 += m4;
    cout << "m3: plus with m4: " << m3 << endl;
    system("pause");
}