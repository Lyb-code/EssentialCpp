#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;

int main() {
    map<string, vector<string>> nameMap;
    vector<string> child1 = {"yuli", "yuyi", "yudi", "yusan"};
    vector<string> child2 = {"jiali", "jiayi", "jiadi", "jiasan"};
    vector<string> child3 = {"keli", "keyi", "kedi", "kesan"};
    vector<string> child4 = {"heli", "heyi", "hedi", "hesan"};
    vector<string> child5 = {"fuli", "fuyi", "fudi", "fusan"};
    vector<string> child6 = {"sili", "siyi", "sidi", "sisan"};
    nameMap["liu"] = child1;
    nameMap["li"] = child2;
    nameMap["mu"] = child3;
    nameMap["zuo"] = child4;
    nameMap["shao"] = child5;
    nameMap["huang"] = child6;
    
    string first_name;
    cout << "Please enter the first name:";
    cin >> first_name;
    if (nameMap.count(first_name)) {
        vector<string> child = nameMap[first_name];
        cout << "The names of all children are as follows:\n";
        for (int i = 0; i < child.size(); i++) {
            cout << child[i] << ' ';
        }
    }

    return 0;
}