#include<iostream>
#include<fstream>
#include<iterator>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class even_elem {
    public:
        bool operator() (int elem) 
            {return elem%2 ? true : false;}
};

int main() {
    ofstream odd_num_file("odd_num_file.txt");
    ofstream even_num_file("even_num_file.txt");
    if (!odd_num_file || !even_num_file) {
        cerr << "!! Unable to open necessary file.\n";
        return -1;
    }

    cout << "Please enter a series of integers.\n";
    istream_iterator<int> is(cin);
    istream_iterator<int> eof;
    vector<int> nums;
    copy(is, eof, back_inserter(nums));
    vector<int>::iterator division = partition(nums.begin(), nums.end(), even_elem());

    ostream_iterator<int> odd_os(odd_num_file, " ");
    ostream_iterator<int> even_os(even_num_file, "\n");
    copy(nums.begin(), division, odd_os);
    copy(division, nums.end(), even_os);
    return 0;
}