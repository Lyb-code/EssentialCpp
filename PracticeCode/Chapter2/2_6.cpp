#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

inline int max(int x1, int x2) {
    return x1 > x2 ? x1 : x2;
}

inline float max(float x1, float x2) {
    return x1 > x2 ? x1 : x2;
}

inline string max(const string& x1, const string& x2) {
    return x1 > x2 ? x1 : x2;
}

//max_element api!!!
template<typename T>
inline T max(const vector<T>& vec) {
    return *max_element(vec.begin(), vec.end());
}

template<typename T>
inline T max(const T *parray, int size) {
    return *max_element(parray, parray+size);
}

int main() {
    string sarray[] = {"we","were","her","pride","of","ten"};
    vector<string> svec(sarray, sarray+6);

    int iarray[] = { 12,70,2,169,1,5,29 };
    vector<int> ivec(iarray, iarray+7 );
    
    float farray[] = { 2.5,24.8,18.7,4.1,23.9};
    vector<float> fvec(farray, farray+5);

    int imax= max(max(ivec), max(iarray, 7));
    float fmax= max(max(fvec), max(farray,5));
    string smax = max(max(svec), max(sarray,6));

    cout <<"imax should be 169-- found:"<<imax <<'\n'
        <<"fmax should be 24.8-- found;"<< fmax<<'\n'
        <<"smax should be were -- found:"<< smax <<'\n';
}