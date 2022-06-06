#include "Stack.h"
#include <iostream>
using namespace std;

int main() {
    Stack st;
    string str;

    while(cin >> str && !st.full()) {
        st.push(str);
    }

    if (st.empty()) {
        cout << '\n' << "Oops: no strings were read -- bailing out\n";
        return 0;
    }

    st.peek(str);
    if (st.size() == 1 && str.empty()) {
        cout << '\n' << "Oops: no strings were read -- bailing out\n";
        return 0;
    }

    cout << '\n' << "Read in " << st.size() << " strings!\n" 
        << "The strings,in reverse order:\n";

    while(st.size()) {
        if (st.pop(str)) {
            cout << str << ' ';
        }
    }

    cout << '\n' << "There are now " << st.size() 
        << " elements in the stack!\n";
    return 0;

}