#include <iostream>
using namespace std;
bool fibon_elem(int, int&);

int main() {
    int pos;
    char ch;
    bool try_more = true;
    while (try_more) {
        cout <<  "Please enter a position: ";
        cin >> pos;
        int elem;
        if (fibon_elem(pos, elem)) {
            cout <<"element #"<< pos
                <<" is"<< elem <<endl;
        } else {
            cout <<"Sorry. Could not calculate element "
                << pos << endl;
        }
        cout << "would you like to try again? (y/n)";
        cin >> ch;
        if (ch == 'n' || ch == 'N')
            try_more = false;
    }
    return 0;
}

bool fibon_elem(int pos, int& elem)
{
    if (pos <= 0 || pos > 1024) {
        elem = 0; return false;
    }
    elem = 1;
    int n_2 = 1, n_1 = 1;
    for (int i = 3; i <= pos; ++i) {
        elem = n_2 + n_1;
        n_2 = n_1;
        n_1 = elem;
    }
    return true;
}