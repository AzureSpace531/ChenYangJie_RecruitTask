#include <iostream>
#include <stdlib.h>
#include <vector>
#include "Matrix.h"

using namespace std;
int main() {
	 
	double nums1[]={1,2,3,4,5,6,7,8,8};
	Matrix M1(nums1,3,3);//һά��������ά�����ʼ��
	double nums2[][3] ={{1,2,3},{4,5,6},{7,8,9}};
	Matrix M2(*nums2,3,3);//��ά�����ʼ��
	
	Matrix MAdd = M1 + M2;//�������
	Matrix Mmin = M1 - M2;//�������	
	Matrix MMul = M1 * M2;//�������
	Matrix MT = M2.Trans(); //����ת��
	Matrix MMulti = M2.Multi(2);//��������

	cout << "M1= " << endl << M1;
	cout << "M2= " << endl << M2;
	cout << "M1+M2= " << endl << MAdd;
	cout << "M1-M2= " << endl << Mmin;
	cout << "M1*M2= " << endl << MMul;
	cout << "M2T= " << endl << MT;
	cout << "M2*2=" << endl << MMulti;
	return 0;
}