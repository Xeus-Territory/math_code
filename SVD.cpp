#include <iostream>
#include "eigen/Eigen/Core"
#include "eigen/Eigen/SVD"
#include "eigen/Eigen/Eigenvalues"
#include <math.h>
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

void MatrixMultiply(float result[][_default], float a[][_default], float b[][_default], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            float sum = 0;
            for (int k = 0; k < n; k++)
            {
                sum = sum + a[i][k] * b[k][j];
            }
            result[i][j] = sum;
        }
    }
}

int main()
{

    MatrixXd A {{3, 1, 0}, {1, 2, 2}, {0, 1, 1}};
    JacobiSVD<MatrixXd> svd(A, ComputeThinU | ComputeThinV);
    cout << "S: " << endl << svd.singularValues() << endl;
    cout << "U: " << endl << svd.matrixU() << endl;
    cout << "V: " << endl << svd.matrixV().transpose() << endl;
    return 0;
}