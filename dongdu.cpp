#include<iostream>
#include<math.h>
using namespace std;

int main(){

    int a, m , n, result;
    cout << "Input a , m , n : ";
    cin >> a >> m >> n;

    // Make code by self 
    if (m == 0)
    {
        result = 1;
    }
    if ( m % 2 == 0){
        result = pow(a, m /2) * pow(a , m / 2);
    }
    if ( m % 2 != 0 ){
        result = pow(a, m - 1) * a; 
    }
    cout << "result : " << (int)result % n << endl;

    // Test by using lib 
    cout << "result by lib : " << fmod(pow(fmod(a , n), m), n);

    return 0;
}