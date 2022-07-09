#ifndef __MATRIX_H__
#define __MATRIX_H__
#include <cmath>
#include <iostream>
#include <stdlib.h>
#include <cmath>

class Matrix {
private:
	double* item;		//指向矩阵首元素的指针
	int rowNum,colNum;		//矩阵行列数	
public:
	Matrix(int m, int n);			 //构建一个m*n的全零矩阵
	Matrix(int n);				 //构建一个n*n的单位矩阵
	Matrix(const Matrix&);		 //拷贝构造函数，深拷贝
	Matrix(double* items, int m, int n);//根据数组拷贝一个矩阵
	~Matrix() {	delete[] item;}

	int getRowNum() const { return rowNum; }				//返回矩阵的行数
	int getColNum() const { return colNum; }				//返回矩阵的列数

	Matrix Trans() const;				//将矩阵转置
	Matrix Multi(double x);				//矩阵数乘
	void RowSwap(int i, int j, double multiply);//交换两行
	void RowSwap(int i, int j);
	double get(int i, int j) const;			//返回矩阵第i行j列元素
	void set(int i, int j, double val);		//设置矩阵第i行j列元素

	Matrix operator +(const Matrix& m);	 	//两个矩阵相加
	Matrix operator -(const Matrix& m);	 	//两个矩阵相减
	Matrix operator *(const Matrix& m);	 	//两个矩阵相乘
	Matrix operator *(const double f);	 	//矩阵乘以常数,这里是矩阵在前，数字在后
	Matrix& operator=(Matrix& m);
	friend std::ostream& operator <<(std::ostream& os, const Matrix& m);//简单重载<<


};

#endif // ! __MATRIX_H__

