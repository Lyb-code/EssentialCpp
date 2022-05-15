#include <iostream>
#include <vector>
using namespace std;
bool pent_elem(int pos, int& elem);
const vector<int>* pent_seq(int pos);
inline bool is_pos_ok(int pos);

int main() {
    int elem;
    if (pent_elem(8, elem)) {
        cout << "element 8 is"<< elem <<'\n';
    }
    if (pent_elem(16, elem)) {
        cout << "element 16 is"<< elem <<'\n';
    }
    if (pent_elem(1000001, elem)) {
        cout << "element 99 is"<< elem <<'\n';
    }
    if (pent_elem(99, elem)) {
        cout << "element 99 is"<< elem <<'\n';
    }
    return 0;
}

bool pent_elem(int pos, int& elem) {
    if (!is_pos_ok(pos)) {
        cout <<"Sorry.Invalid position:"<< pos << endl; 
        elem= 0; 
        return false;
    } 
    const vector<int>* vec = pent_seq(pos);
    elem = (*vec)[pos-1]; 
    return true;
}

const vector<int>* pent_seq(int pos) {
    static vector<int> _elems;
    if (is_pos_ok(pos) && (pos > _elems.size())) {
        for (int i = _elems.size()+1; i <= pos; i++) {
            _elems.push_back(i*(3*i-1) / 2);
        }
    }
    return &_elems;
}

inline bool is_pos_ok(int pos) {
    return (pos > 0 && pos < 10000) ? true : false; 
}