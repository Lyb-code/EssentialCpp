#include<iostream>
#include<string>
#include<vector>
using namespace std;

typedef string elemType;
class Stack {
public:
    Stack(int capacity = 0) : _top(0) 
        { if(capacity)_stack.reserve(capacity); }
    virtual ~Stack(){}
    bool pop(elemType&);
    virtual bool peek(int index, elemType&) { return false; }
    bool push(const elemType&);
    int top() const { return _top; }
    int size() const { return _stack.size(); }
    bool empty() const { return !_top; }
    bool full() const { return size() >= _stack.max_size(); }
    void print(ostream& = cout) const;

protected:
    vector<elemType> _stack;
    int _top;
};

bool Stack::pop(elemType &elem) {
    if (empty()) return false;
    elem = _stack[--_top];
    _stack.pop_back();
    return true;
}

bool Stack::push(const elemType &elem) {
    if (full()) return false;
    _stack.push_back(elem);
    _top++;
    return true;
}

void Stack::print(ostream &os) const {
    vector<elemType>::const_reverse_iterator 
        rit = _stack.rbegin(), 
        rend = _stack.rend();
    os << "\n\t";
    while (rit != rend) 
        os << *rit++ << "\n\t";
    os << endl;
}

ostream& operator <<(ostream &os, const Stack &rhs)
    {rhs.print(os); return os;}


class LIFO_Stack : public Stack {
public:
    LIFO_Stack(int capacity = 0) : Stack(capacity) {}
};

//让用户在不更改 stack元素的前提下，访问任何一个元素。
class Peekback_Stack : public Stack {
public:
    Peekback_Stack(int capacity = 0) : Stack(capacity) {}
    virtual bool peek(int index,elemType &elem);
};

bool Peekback_Stack::peek(int index, elemType &elem) {
    if (empty())
        return false;
    if (index < 0 || index >= size())
        return false;

    elem = _stack[index];
    return true;
}

void peek(Stack &st, int index) {
    cout << endl;
    string t;
    if (st.peek(index, t))
        cout << "Peek: " << t;
    else cout << "Peek failed!";
    cout << endl;
}