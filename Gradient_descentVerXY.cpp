#include <iostream>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
// Sort base on basis of min absolute value or err
bool Custom_Sort(double a, double b)
{
    double a1 = abs(a - 0);
    double a2 = abs(b - 0);
    return a1 < a2;
}

int main()
{
    //Intialization Phase
    double x[] = {1, 2, 3, 4, 5};
    double y[] = {3, 3, 3, 2, 5};

    // Variables value
    vector<double> errors ; // Store err value 
    double err; // Calculate err value
    double b0 = 0; 
    double b1 = 0 ;
    double alpha = 0.01; 

    for (int i = 0; i < 20; i++){ // 20 loop for 4 epochs and 5 value 
        int idx = i % 5;
        double p = b0 + b1 * x[idx]; // Calculate predict 
        err = p - y[idx];
        b0 = b0 - alpha * err;
        b1 = b1 - alpha * err * x[idx];
        cout << "B0 = " << b0 << ", B1 =" << b1 <<  ", error = " << err << endl;
        errors.push_back(err);
    }
    // Take final value of Gradient descent
    sort(errors.begin(), errors.end(), Custom_Sort);
    cout << "Final Value are = " << "B0 = " << b0 << ", B1 = " << b1 << ", error = " << errors[0] << endl;

    // Predict Value on Linear regression test
    cout << "Enter x value: "; 
    double test; 
    cin >> test;
    double predict = b0 + b1 * test;
    cout << "The value predicted by the model = " << predict;
}