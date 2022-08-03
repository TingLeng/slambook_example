#include<iostream>
#include<Eigen/Core>

//包含几何模块
#include<Eigen/Geometry>
using namespace std;

int main(int argc,char **argv)
{
    /*变量定义*/
    Eigen::Quaterniond Q1(0.2,0.3,0.1,0.35); //四元数的表示(w ,x,y,z)
    Eigen::Quaterniond Q2(0.4,-0.1,0.2,-0.5);
    Eigen::Vector3d t1(0.3,0.1,0.1);
    Eigen::Vector3d t2(-0.1,0.5,0.3);
    Eigen::Vector3d p(0.5,0,0.2);   //在一号小萝卜下的坐标
    Eigen::Vector3d pw ;            //世界坐标
    Eigen::Vector3d p2;             //求在二号小萝卜的坐标 p2

   /*欧氏变换矩阵使用Eigen::Isometry */
    Eigen::Isometry3d T_1w = Eigen::Isometry3d::Identity();
    Eigen::Isometry3d T_2w = Eigen::Isometry3d::Identity();

    /*归一化*/
    Q1.normalize();
    Q2.normalize();

    /*输出归一化参数*/
//    cout<<"Q1 is "<<Q1.x()<<endl<<Q1.y()<< endl <<Q1.z()<< endl<<Q1.w()<<endl;
//    cout<<"Q2 is "<<Q2.x()<<endl<<Q2.y()<< endl <<Q2.z()<< endl<<Q2.w()<<endl;

    cout<<"after normalize； "<< endl << Q2.coeffs()<<endl;

    /*设置变换矩阵的参数*/
    T_1w.rotate(Q1);
    T_1w.pretranslate(t1);
    T_2w.rotate(Q2);
    T_2w.pretranslate(t2);

    /* p = T1w * pw  求解pw*/
    pw = T_1w.inverse() * p;

    /* p2 = T_2w * pw  求解p2*/
    p2 = T_2w * pw;

    /*输出在小萝卜二号下的该点坐标*/
    cout<<"该点在小萝卜二号下的坐标为: "<<p2.transpose()<<endl;

    return 0;
}