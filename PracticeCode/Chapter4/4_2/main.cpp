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

    cout << '\n' << "Read in " << st.size() << " strings!\n" ;
    cin.clear();//清除end-of-file的设定

    cout << "what word to search for? ";
    cin >> str;

    bool found = st.find(str);
    int count = found ? st.count(str) : 0;

    cout << str << (found ? " is " : " isn\'t ") << "in the stack. ";
    if (found) 
        cout << "It occurs " << count << " times\n";
    return 0;

}