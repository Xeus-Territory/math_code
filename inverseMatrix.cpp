#include<iostream>
using namespace std;
#define default_ 100

void MatrixBuild(float Matrix[][default_], int n);
void MatrixRender(float Matrix[][default_], int n);
void inverseMatrix(float Matrix[][default_], int n);

int main(){

    float Matrix[default_][default_];
    int n; 
    cout << "Input Level of Matrix: ";
    cin >> n; 
    MatrixBuild(Matrix, n);
    cout << endl;
    cout << "Matrix Begin : " << endl;
    MatrixRender(Matrix, n);
    cout << endl;
    cout << "Output of Inverse Matrix: " << endl;
    inverseMatrix(Matrix, n);
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

void inverseMatrix(float Matrix[][default_], int n)
{
    float ratio, a ;
    // Tạo ma trận đơn vị
    for (int i = 0; i < n; i++)
    {
        for (int j = n; j < 2 * n; j++)
        {
            if(i == (j - n))
                Matrix[i][j] = 1.0; 
            else
                Matrix[i][j] = 0.0;
        }
    }
    // Tìm hệ số và tính hàng trước theo hệ số 
    for (int i = 0 ; i < n ; i++)
    {
        for (int j = 0 ; j < n ; j++)
        {
            if(i != j)
            {
                ratio = Matrix[j][i] / Matrix[i][i];
                for (int k = 0 ; k < 2 * n ; k++)
                {
                    Matrix[j][k] -= ratio * Matrix[i][k]; 
                }
            }
        }
    }
    // Biến đổi ma trận theo đường chéo chính 
    for (int i = 0 ; i < n ; i++)
    {
        a = Matrix[i][i];
        for (int j = 0; j < 2 * n; j++)
        {
            Matrix[i][j] /= a;
        }
    }
    for (int i = 0 ; i < n ; i++)
    {
        for (int j = n; j < 2 * n; j++)
        {
            cout << Matrix[i][j] << " ";
        }
        cout << endl;
    }
}