#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool pent_seq(int size, vector<int>& inV);
void display(const vector<int>& vec, const string& type, ostream &os = cout);

int main() {
    int size;
    cout << "Please enter the size of array: ";
    cin >> size;
    vector<int> vec;
    const string title("Pentagonal");
    if (pent_seq(size, vec)) {
        display(vec, title);
    }
    return 0;
}

bool pent_seq(int size, vector<int>& vec) {
    if (size <= 0 || size > 10000) {
        cerr <<"Invalld size:"<< size << endl;
        return false;
    }
    for (int i = vec.size()+1; i <= size; ++i) {
        vec.push_back(i*(3*i-1) / 2);
    }
    return true;
}

void display(const vector<int>& vec, const string& type, ostream &os) {
    os << "The type of the array is: " << type << "\n\t";
    for (int i = 0; i < vec.size(); i++) {
        os << vec[i] << ' ';
    }
    os << '\n';
}