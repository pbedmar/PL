#include <iostream>
using namespace std;

int b = 2;

int main() {

    auto f = [=](string s = "h"){ 
        cout << b << s; 
    };

    f();
}