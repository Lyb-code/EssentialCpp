#include "Stack.h"

bool Stack::push(const string& elem) {
    if (full()) return false;
    _stack.push_back(elem);
    return true;
}

bool Stack::pop(string& elem) {
    if (empty()) return false;
    elem = _stack.back();
    _stack.pop_back();
    return true;
}

bool Stack::peek(string& elem) {
    if (empty()) return false;
    elem = _stack.back();
    return true;
}

bool Stack::find(const string& elem) {
    Stack copy_stack;
    bool found = false;
    string exist_elem;
    while (this->pop(exist_elem) && !found) {
        if (exist_elem == elem) found = true;
        copy_stack.push(exist_elem);
    }
    while (copy_stack.pop(exist_elem)) {
        this->push(exist_elem);
    }
    return found;
}

int Stack::count(const string & elem) {
    Stack copy_stack;
    int cnt = 0;
    string exist_elem;
    while (this->pop(exist_elem)) {
        if (exist_elem == elem) cnt++;
        copy_stack.push(exist_elem);
    }
    while (copy_stack.pop(exist_elem)) {
        this->push(exist_elem);
    }
    return cnt;
}