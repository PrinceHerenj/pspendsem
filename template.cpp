#include <iostream>
using namespace std;

template<class T, class F>
T add(T a, F b) {
    cout << "Base Template" << endl;
    return a + b;
}

int add(int a, int b) {
    cout << "Overloaded Template" << endl;
    return a + b;
}

int main() {
    cout << add<int>(1,2) << endl;
    cout << add<float, int>(1.0, 2) << endl;
    cout << add(1,2) << endl;
}