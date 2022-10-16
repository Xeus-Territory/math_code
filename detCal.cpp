#include<iostream>
#include<math.h>
#define default_ 100
using namespace std;

void MatrixBuild(float Matrix[][default_], int n);
void MatrixRender(float Matrix[][default_], int n);
float detCal(float Matrix[][default_], int n);


int main(){
    float Matrix[default_][default_];
    int n; 
    cout << "Input Level of Matrix: ";
    cin >> n; 
    MatrixBuild(Matrix, n);
    cout << endl;
    MatrixRender(Matrix, n);
    cout << endl;
    cout << " Det of Matrix = " << detCal(Matrix, n);
    return 0;
}

void MatrixBuild(float Matrix[][default_], int n)
{
    for (int i = 0 ; i < n ; i++)
    {
        for (int j = 0 ; j < n ; j++)
        {
            cout << "Matrix [" << i + 1 << "][" << j + 1 << "] : ";
            cin >> Matrix[i][j];
        }
    }
}

void MatrixRender(float Matrix[][default_], int n)
{
    for (int i = 0 ; i < n ; i++)
    {
        for (int j = 0 ; j < n ; j++)
        {
            cout << Matrix[i][j] << " ";
        }
        cout << endl;
    }
}

float detCal(float Matrix[][default_], int n)
{
    int dem = 0 , kt;   
    float b[default_], c[default_], d[default_], h , det = 1;
    for (int i = 0; i < n - 1 ; i++)
    {
        if (Matrix[i][i] == 0)
        {
            kt = 0;
            for (int j = 0 ; j < n ; j++)
            {
                if(Matrix[i][j] != 0)
                for(int k = 0 ; k < n ; k++)
                {
                    c[k] = Matrix[k][i];
                    Matrix[k][i] = Matrix[k][j];
                    Matrix[k][j] = c[k];
                }
                dem++;
                kt++;
                break;
            }
        }
        if(kt == 0 ) return 0;
        b[i] = Matrix[i][i];
        for (int j  = 0 ; j < n ; j++) Matrix[i][j] /= b[i];
        for (int j =  i + 1; j < n; j++)
        {
            h = Matrix[j][i];
            for (int k = 0 ; k < n ; k++) Matrix[j][k] -= h * Matrix[i][k];
        }
    }
    b[n - 1] = Matrix[n - 1][n - 1];
    for (int i = 0 ; i < n ; i++)
    {
        det = det * b[i];
    }
    if (dem % 2 == 0) return det;
    else return -det;
}