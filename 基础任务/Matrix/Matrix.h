#ifndef __MATRIX_H__
#define __MATRIX_H__
#include <cmath>
#include <iostream>
#include <stdlib.h>
#include <cmath>

class Matrix {
private:
	double* item;		//ָ�������Ԫ�ص�ָ��
	int rowNum,colNum;		//����������	
public:
	Matrix(int m, int n);			 //����һ��m*n��ȫ�����
	Matrix(int n);				 //����һ��n*n�ĵ�λ����
	Matrix(const Matrix&);		 //�������캯�������
	Matrix(double* items, int m, int n);//�������鿽��һ������
	~Matrix() {	delete[] item;}

	int getRowNum() const { return rowNum; }				//���ؾ��������
	int getColNum() const { return colNum; }				//���ؾ��������

	Matrix Trans() const;				//������ת��
	Matrix Multi(double x);				//��������
	void RowSwap(int i, int j, double multiply);//��������
	void RowSwap(int i, int j);
	double get(int i, int j) const;			//���ؾ����i��j��Ԫ��
	void set(int i, int j, double val);		//���þ����i��j��Ԫ��

	Matrix operator +(const Matrix& m);	 	//�����������
	Matrix operator -(const Matrix& m);	 	//�����������
	Matrix operator *(const Matrix& m);	 	//�����������
	Matrix operator *(const double f);	 	//������Գ���,�����Ǿ�����ǰ�������ں�
	Matrix& operator=(Matrix& m);
	friend std::ostream& operator <<(std::ostream& os, const Matrix& m);//������<<


};

#endif // ! __MATRIX_H__

