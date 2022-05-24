#include<iostream>
#include<fstream>
#include<iterator>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class cmp {
    public:
        bool operator() (const string& str1, const string& str2) {
            return str1.length() < str2.length();
        }
};

template <typename elemType>
void display_vector(const vector<elemType> &vec, ostream &os = cout, int len = 8) {
    typename vector<elemType>::const_iterator iter = vec.begin(), end_it = vec.end();

    int elem_cnt = 1;
    while (iter != end_it) {
        os << *iter++ << (!(elem_cnt++ % len) ? '\n' : ' ');
    }
    os << endl;
}

int main() {
    ifstream in_file("input_file1.txt");
    if (!in_file) {
        cerr << "!! Unable to open input file.\n";
        return -1;
    }
    
    string word;
    vector<string> v;
    while (in_file >> word) {
        v.push_back(word);
    }
    
    sort(v.begin(), v.end(), cmp());
    cout << "The contents of the sorted vector:.\n";
    display_vector(v);

    return 0;
}