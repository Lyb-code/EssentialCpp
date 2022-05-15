#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool pent_seq(int size, vector<int>& inV);
inline bool is_size_ok(int size);
void cal_vec(int size, vector<int>& vec);
void display(const vector<int>& vec, const string& type, ostream &os = cout);

int main() {
    // int size;
    // cout << "Please enter the size of array: ";
    // cin >> size;
    vector<int> vec;
    const string title("Pentagonal");
    if (pent_seq(0, vec)) {
        display(vec, title);
    }
    if (pent_seq(8, vec)) {
        display(vec, title);
    }
    if (pent_seq(16, vec)) {
        display(vec, title);
    }
    if (pent_seq(100001, vec)) {
        display(vec, title);
    }
    return 0;
}

bool pent_seq(int size, vector<int>& vec) {
    if (is_size_ok(size)) {
        if (size > vec.size()) cal_vec(size, vec);
        return true;
    } else {
        return false;
    }
}

inline bool is_size_ok(int size) {
    if (size <= 0 || size > 10000) {
        cerr <<"Invalld size:"<< size << endl;
        return false;
    }
    return true;
}

void cal_vec(int size, vector<int>& vec) {
    for (int i = vec.size()+1; i <= size; i++) {
        vec.push_back(i*(3*i-1) / 2);
    }
}

void display(const vector<int>& vec, const string& type, ostream &os) {
    os << "The type of the array is: " << type << "\n\t";
    for (int i = 0; i < vec.size(); i++) {
        os << vec[i] << ' ';
    }
    os << '\n';
}