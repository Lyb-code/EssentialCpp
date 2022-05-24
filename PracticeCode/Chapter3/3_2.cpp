#include<iostream>
#include<fstream>
#include<map>
#include<set>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class cmp {
    public:
        bool operator() (string str1, string str2) {
            return str1.length() < str2.length();
        }
};

int main() {
    ifstream in_file("input_file1.txt");
    if (!in_file) {
        cerr << "!! Unable to open input file.\n";
        return -1;
    }
    
    string word;
    string exclude_words[6] = {"a", "an", "or", "the", "and", "but"};
    map<string, int> wordCnt;
    map<string, int>::iterator it;
    set<string> word_exclusion(exclude_words, exclude_words+6);
    while (in_file >> word) {
        if (!word_exclusion.count(word)) {
            wordCnt[word]++;
        }
    }
    
    vector<string> v;
    for (it = wordCnt.begin(); it != wordCnt.end(); ++it)
        v.push_back(it->first);
    
    sort(v.begin(), v.end(), cmp());
    cout << "The contents of the sorted vector:.\n";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    }

    return 0;
}