#include <stdexcept>
#include <string>
using namespace std;

class StackException : public logic_error{
public:
    StackException(const char *what) : _what(what), logic_error("base") {}
    const char* what() const { return _what.c_str(); }

protected:
    string _what;
};

class PopOnEmpty : public StackException {
public:
    PopOnEmpty() : StackException("Pop on Empty Stack") {}
};

class PushOnFull : public StackException {
public:
    PushOnFull() : StackException("Push on Full Stack") {}
};