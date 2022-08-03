#include<iostream>
#include<Eigen/Dense>

using namespace std;
using namespace Eigen;

int main(int argc, char** argv)
{
    const int SIZE = 8;
    MatrixXd m = MatrixXd::Random(SIZE, SIZE);
    MatrixXd v = m.block(0,0,3,3);
    //m.block(0,0,3,3) = MatrixXd::Identity(3,3);
    //m.topLeftCorner(3, 3) = MatrixXd::Identity(3,3);
    m.topLeftCorner(3,3).setIdentity();
    cout << m << endl;
    cout << v << endl;

}