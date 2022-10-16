#include <iostream>
#include <cstdlib>
#include "eigen/Eigen/Core"
#include "eigen/Eigen/SVD"
#include "eigen/Eigen/Eigenvalues"
#include "eigen/unsupported/Eigen/MatrixFunctions"
#include <math.h>
#define _default 100
using namespace std;
using namespace Eigen;

int main()
{
     MatrixXd A{{3, -1}, {-1, 5}};
     //MatrixXd A = MatrixXd::Random(rand() % 100, rand() % 100);
     //MatrixXd A = MatrixXd::Random(3 , 3);
     cout << "Here is a random 3x3 matrix, A:" << endl
          << A << endl
          << endl;
     MatrixXd AT = A.transpose();

     //Computing U
     MatrixXd AAT = A * AT;
     EigenSolver<MatrixXd> U(AAT);
     cout << "Here is a EigenValue of AAT:  " << endl
          << U.eigenvalues() << endl
          << endl;
     //MatrixXd UeigenVec = U.pseudoEigenvectors();
     MatrixXd UeigenVec(U.eigenvectors().cols(), U.eigenvectors().cols());
     for (int i = 0; i < U.eigenvectors().cols(); i++)
     {
          for (int j = 0; j < U.eigenvectors().cols(); j++)
          {
               complex<double> lamda = U.eigenvectors().col(i)[j];
               complex<double> check(0);
               if (lamda.real() > 0)
               {
                    const double point = std::abs(lamda);
                    UeigenVec(j, i) = point;
               }
               else
               {
                    const double point = -1 * std::abs(lamda);
                    UeigenVec(j, i) = point;
               }
          }
     }
     cout << "Here is a U is Left Singular AAT: " << endl
          << UeigenVec << endl
          << endl;

     // Computing V
     MatrixXd ATA = AT * A;
     EigenSolver<MatrixXd> V(ATA);
     cout << "Here is a EigenValue of ATA:  " << endl
          << V.eigenvalues() << endl
          << endl;
     //MatrixXd VeigenVec = V.pseudoEigenvectors();
     MatrixXd VeigenVec(V.eigenvectors().cols(), V.eigenvectors().cols());
     for (int i = 0; i < V.eigenvectors().cols(); i++)
     {
          for (int j = 0; j < V.eigenvectors().cols(); j++)
          {
               complex<double> lamda = V.eigenvectors().col(i)[j];
               complex<double> check(0);
               if (lamda.real() > 0)
               {
                    const double point = std::abs(lamda);
                    VeigenVec(j, i) = point;
               }
               else
               {
                    const double point = -1 * std::abs(lamda);
                    VeigenVec(j, i) = point;
               }
          }
     }
     cout << "Here is a V is Right Singular ATA: " << endl
          << VeigenVec.transpose() << endl
          << endl;

     // Computing D
     MatrixXd m(V.eigenvalues().rows(), 1);
     for (int i = 0; i < V.eigenvalues().rows(); i++)
     {
          complex<double> lamda = V.eigenvalues()[i];
          const double point = std::abs(lamda);
          m(i, 0) = point;
     }
     MatrixXd SingularDiagonalD = m.array().sqrt().matrix().asDiagonal();
     cout << "Here is a SingularDiagonal D: " << endl
          << SingularDiagonalD << endl
          << endl;

     //Result Check
     MatrixXd result = UeigenVec * SingularDiagonalD * VeigenVec.transpose();
     cout << "Here is a result of Multiple all Matrix: " << endl
          << result << endl
          << endl;
     return 0;
}
