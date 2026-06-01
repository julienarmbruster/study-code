#include <iostream>
#include <string>

template<typename T1, typename T2>
class Pair {
    private:
    T1 first;
    T2 second;

    public:
    Pair(const T1 &a, const T2 &b) : first(a), second(b) {}
    const T1& getFirst() const { return first; }
    const T2& getSecond() const { return second; }
    void setFirst(const T1& a) { first = a; }
    void setSecond(const T2& b) { second = b; }
};

