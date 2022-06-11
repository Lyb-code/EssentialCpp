#include<iostream>
#include<string>
#include<vector>
using namespace std;

typedef string elemType;
class Stack {
public:
    virtual ~Stack(){}
    virtual bool pop(elemType&) = 0;
    virtual bool peek(int index, elemType&) = 0;
    virtual bool push(const elemType&) = 0;
    virtual int top() const = 0;
    virtual int size() const = 0;
    virtual bool empty() const = 0;
    virtual bool full() const = 0;
    virtual void print(ostream& = cout) const = 0;
};

ostream& operator <<(ostream &os, const Stack &rhs)
    {rhs.print(os); return os;}

class LIFO_Stack : public Stack {
public:
    LIFO_Stack(int capacity = 0) : _top(0) 
        { if(capacity)_stack.reserve(capacity); }
    bool pop(elemType &elem);
    bool peek(int index, elemType &elem) { return false; }
    bool push(const elemType&);
    int top() const { return _top; }
    int size() const { return _stack.size(); }
    bool empty() const { return !_top; }
    bool full() const { return size() >= _stack.max_size(); }
    void print(ostream& = cout) const;

private:
    vector<elemType> _stack;
    int _top;
};

bool LIFO_Stack::pop(elemType &elem) {
    if (empty()) return false;
    elem = _stack[--_top];
    _stack.pop_back();
    return true;
}

bool LIFO_Stack::push(const elemType &elem) {
    if (full()) return false;
    _stack.push_back(elem);
    _top++;
    return true;
}

void LIFO_Stack::print(ostream &os) const {
    vector<elemType>::const_reverse_iterator 
        rit = _stack.rbegin(), 
        rend = _stack.rend();
    os << "\n\t";
    while (rit != rend) 
        os << *rit++ << "\n\t";
    os << endl;
}

//让用户在不更改 stack元素的前提下，访问任何一个元素。
class Peekback_Stack : public Stack {
public:
    Peekback_Stack(int capacity = 0) : _top(0) 
        { _stack.reserve(capacity); }
    bool pop(elemType &elem);
    bool peek(int index, elemType &elem);
    bool push(const elemType&);
    int top() const { return _top; }
    int size() const { return _stack.size(); }
    bool empty() const { return !_top; }
    bool full() const { return size() >= _stack.max_size(); }
    void print(ostream& = cout) const;

private:
    vector<elemType> _stack;
    int _top;
};

bool Peekback_Stack::pop(elemType &elem) {
    if (empty()) return false;
    elem = _stack[--_top];
    _stack.pop_back();
    return true;
}

bool Peekback_Stack::peek(int index, elemType &elem) {
    if (empty())
        return false;
    if (index < 0 || index >= size())
        return false;

    elem = _stack[index];
    return true;
}

bool Peekback_Stack::push(const elemType &elem) {
    if (full()) return false;
    _stack.push_back(elem);
    _top++;
    return true;
}

void Peekback_Stack::print(ostream &os) const {
    vector<elemType>::const_reverse_iterator 
        rit = _stack.rbegin(), 
        rend = _stack.rend();
    os << "\n\t";
    while (rit != rend) 
        os << *rit++ << "\n\t";
    os << endl;
}

void peek(Stack &st, int index) {
    cout << endl;
    string t;
    if (st.peek(index, t))
        cout << "Peek: " << t;
    else cout << "Peek failed!";
    cout << endl;
}