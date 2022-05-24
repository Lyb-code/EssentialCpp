#include<iostream>
#include<fstream>
#include<iterator>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

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
    vector<int> nums, odd_nums, even_nums;
    copy(is, eof, back_inserter(nums));
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] % 2) {
            odd_nums.push_back(nums[i]);
        } else {
            even_nums.push_back(nums[i]);
        }
    }

    ostream_iterator<int> odd_os(odd_num_file, " ");
    ostream_iterator<int> even_os(even_num_file, "\n");
    copy(odd_nums.begin(), odd_nums.end(), odd_os);
    copy(even_nums.begin(), even_nums.end(), even_os);
    return 0;
}