#include<iostream>
#include<fstream>
#include<map>
#include<set>
#include<string>
using namespace std;


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

    cout << "Please enter the word you want to query:";
    cin >> word;
    it = wordCnt.find(word);
    if (it != wordCnt.end()) {
        cout << '\"' << word << "\" exists in file with occurrences of "<< it->second << ".\n";
    } else {
        cout << word << " does not exist in file.\n";
    }

    
    for (it = wordCnt.begin(); it != wordCnt.end(); ++it)
        cout << "Word: \"" << it->first 
                << "\" Count: " << it->second << endl;

    return 0;
}