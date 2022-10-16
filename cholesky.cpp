#include<iostream>
#include<math.h>
#include<vector>
#include<iterator>
#include "eigen\Eigen\Eigenvalues"
#include "eigen\Eigen\src\Core\Matrix.h"
#define _default 100
using namespace std;
using namespace Eigen;

void MatrixBuild(float Matrix[][_default], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Matrix [" << i + 1 << "][" << j + 1 << "] : ";
            cin >> Matrix[i][j];
        }
    }
}

void MatrixRender(float Matrix[][_default], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << Matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void Cholesky(float LeftDiagonal[][_default], float Matrix[][_default], int n)
{
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            int sum = 0;
            if (j == i)
            {
                for (int k = 0; k < j; k++)
                    sum += pow(LeftDiagonal[j][k] , 2);
                LeftDiagonal[j][j] = sqrt(Matrix[i][j] - sum);
            }
            else
            {
                for (int k = 0; k < j; k++)
                    sum += LeftDiagonal[i][k] * LeftDiagonal[j][k];
                LeftDiagonal[i][j] = (Matrix[i][j] - sum) / LeftDiagonal[j][j];
            }
        }
    }
}
void Tranpose(float Matrix[][_default], float Matrix1[][_default], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            Matrix1[i][j] = Matrix[j][i];
        }
    }
}
bool CheckEV(float arr[])
{
    bool check = false;
    for (int i = 0 ; i < sizeof(arr) / sizeof(float); i++)
    {
        if (arr[i] > 0) check = true;
    }
    return check;
}
int main()
{
    float MatrixInput[_default][_default], LeftDiagonal[_default][_default], RightDiagonal[_default][_default];
    float ev[_default];
    int n; 
    cout << "Input Level of Matrix: "; cin >> n;
    MatrixBuild(MatrixInput, n);
    Cholesky(LeftDiagonal, MatrixInput, n);
    cout << "\n" <<"Output of Matrix L: " << endl;
    MatrixRender(LeftDiagonal, n);
    Tranpose(LeftDiagonal, RightDiagonal, n);
    cout << "\n" <<"Output of Matrix Tranpose L: " << endl;
    MatrixRender(RightDiagonal, n);
    return 0;
}