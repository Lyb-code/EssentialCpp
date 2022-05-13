#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
using namespace std;

// C-style
void getNameInCStyle() {
    // char array instead of char pointer!!!
    const int nm_size = 128;
    char name[nm_size];
    cout << "Please enter your name:";
    cin >> setw(nm_size) >> name;
    switch (strlen(name)) {
        case 0:
            cout << "Hi, user with no name";
            break;
        case 1:
            cout << "name is too short";
            break;
        case 127:
            cout << "The name is too long and is shortened";
        default:
            cout << "Hello, " << name
                << ".Welcome!";
            break;
    }
}

// Use string
void getNameByString() {
    string name;
    cout << "Please enter your name:";
    cin >> name;
    switch (name.length()) {
        case 0:
            cout << "Hi, user with no name";
            break;
        case 1:
            cout << "name is too short";
            break;
        default:
            cout << "Hello, " << name
                << ".Welcome!";
            break;
    }
}

int main() {
    getNameInCStyle();
    // getNameByString();
    return 0;
}