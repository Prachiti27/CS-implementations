#include <iostream>

using namespace std;

int gcd(int a, int b) {
    while(b != 0) {
        int rem = a % b;
        a = b;
        b = rem;
    }
    return (a < 0) ? -a : a;
}

int main() {
    int a,b;
    cout<<"Enter two integers: ";
    cin>>a>>b;
    cout<<"GCD = "<<gcd(a,b)<<endl;
}