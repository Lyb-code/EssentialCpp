#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    vector<string> sv;
    string word;
    ifstream infile("testInput.txt");
    if (!infile) {
        cerr << "Unable to open input file!\n";
        return -1;
    }
    ofstream outfile("testOutput.txt");
    if (!outfile) {
        cerr << "Oops! Unable to open output file!\n";
        return -2;
    }

    while (infile >> word) {
        sv.push_back(word);
    } 
    for (int i = 0; i < sv.size(); i++) {
        cout << sv[i] << endl;
    }
    sort(sv.begin(), sv.end());
    
    for (int i = 0; i < sv.size(); i++) {
        outfile << sv[i] << endl;
    }

    return 0;
}