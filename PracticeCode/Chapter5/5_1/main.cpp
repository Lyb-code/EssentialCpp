#include "Stack.h"

int main() {
    LIFO_Stack st;
    string str;
    while (cin >> str && !st.full())
        st.push(str);
    cout << '\n' << "About to call peek() with LIFO_Stack" << endl;
    peek(st, st.top() - 1);
    cout << st;

    Peekback_Stack pst;
    while (!st.empty()) {
        string t;
        if (st.pop(t))
            pst.push(t);
    }
    cout << "About to call peek()with Peekback_Stack" << endl;
    peek(pst, pst.top()-1);
    cout << pst;
    return 0;
}