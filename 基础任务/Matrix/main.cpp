#include <iostream>
#include <stdlib.h>
#include <vector>
#include "Matrix.h"

using namespace std;
int main() {
	 
	double nums1[]={1,2,3,4,5,6,7,8,8};
	Matrix M1(nums1,3,3);//一维数组代替二维数组初始化
	double nums2[][3] ={{1,2,3},{4,5,6},{7,8,9}};
	Matrix M2(*nums2,3,3);//二维数组初始化
	
	Matrix MAdd = M1 + M2;//矩阵相加
	Matrix Mmin = M1 - M2;//矩阵相减	
	Matrix MMul = M1 * M2;//矩阵相乘
	Matrix MT = M2.Trans(); //矩阵转置
	Matrix MMulti = M2.Multi(2);//矩阵数乘

	cout << "M1= " << endl << M1;
	cout << "M2= " << endl << M2;
	cout << "M1+M2= " << endl << MAdd;
	cout << "M1-M2= " << endl << Mmin;
	cout << "M1*M2= " << endl << MMul;
	cout << "M2T= " << endl << MT;
	cout << "M2*2=" << endl << MMulti;
	return 0;
}