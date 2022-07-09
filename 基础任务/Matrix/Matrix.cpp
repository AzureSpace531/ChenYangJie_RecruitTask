#include "Matrix.h"
#include <iostream>
#include <cmath>

using namespace std;
Matrix::Matrix(int m, int n){
	if (m < 0 || n < 0){
		cout << "Error\n";
		return;
	}
	rowNum = m;
	colNum = n;
	item = new double[m * n];
	for (int i = 0; i < m * n; i++){
		item[i] = 0;
	}
}

//用二维数组初始化
Matrix::Matrix(double* items, int m, int n){
	rowNum = m;
	colNum = n;
	item = new double[m * n];
	for (int i = 0; i < colNum * rowNum; i++){
		item[i] = items[i];
	}
}
Matrix::Matrix(int n){
	rowNum = colNum = n;
	item = new double[n * n];
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (i == j)
				set(i, j, 1);
			else
				set(i, j, 0);
		}
	}
}

Matrix::Matrix(const Matrix& M){
	colNum = M.colNum;
	rowNum = M.rowNum;
	item = new double[colNum * rowNum];
	for (int i = 0; i < colNum * rowNum; i++){
		item[i] = M.item[i];
	}
}

Matrix& Matrix::operator=(Matrix& M){
	colNum = M.colNum;
	rowNum = M.rowNum;
	if (item != nullptr) delete[] item;
	item = new double[colNum * rowNum];
	for (int i = 0; i < colNum * rowNum; i++){
		item[i] = M.item[i];
	}
	return *this;
}

double Matrix::get(int i, int j) const{
	return item[i * colNum + j];
}

void Matrix::set(int i, int j, double value){
	item[i * colNum + j] = value;
}

void Matrix::RowSwap(int i, int j, double multiply){
	if (j == -1)
	{
		for (int k = 0; k < colNum; k++)
		{
			set(i, k, multiply * get(i, k));
		}
	}
	else
	{
		for (int k = 0; k < colNum; k++)
		{
			set(j, k, multiply * get(i, k) + get(j, k));
		}
	}
}

void Matrix::RowSwap(int i, int j){
	Matrix _copy = *this;
	for (int k = 0; k < colNum; k++)
	{
		double swap = _copy.get(j, k);
		set(j, k, _copy.get(i, k));
		set(i, k, swap);
	}
}

Matrix Matrix::Trans() const{
	Matrix _copy = *this;
	for (int i = 0; i < rowNum; i++)
	{
		for (int j = 0; j < colNum; j++)
		{
			_copy.set(i, j, get(j, i));
		}
	}
	_copy.rowNum = this->colNum;
	_copy.colNum = this->rowNum;
	return _copy;
}

Matrix Matrix::Multi(double x){
	Matrix _copy = *this;
	if (x != 0) {
		for (int i = 0; i < rowNum; i++)
		{
			for (int j = 0; j < colNum; j++)
			{
				_copy.set(i, j, get(j, i)*x);
			}
		}
	}
	return _copy;
}

ostream& operator <<(ostream& os, const Matrix& m){
	for (int i = 0; i < m.rowNum; i++){
		for (int j = 0; j < m.colNum; j++){
			os << m.get(i, j);
			if (j != m.colNum - 1) os << " ";
			else os << "\n";
		}
	}
	return os;
}

Matrix Matrix::operator +(const Matrix& m){
	if (m.colNum != colNum || m.rowNum != rowNum) return *this;
	Matrix _copy = *this;
	for (int i = 0; i < rowNum; i++)
	{
		for (int j = 0; j < colNum; j++)
		{
			_copy.set(i, j, get(i, j) + m.get(i, j));
		}
	}
	return _copy;
}

Matrix Matrix::operator -(const Matrix& m){
	if (m.colNum != colNum || m.rowNum != rowNum) return *this;
	Matrix _copy = *this;
	for (int i = 0; i < rowNum; i++){
		for (int j = 0; j < colNum; j++){
			_copy.set(i, j, get(i, j) - m.get(i, j));
		}
	}
	return _copy;
}

Matrix Matrix::operator *(const double f){
	Matrix _copy = *this;
	for (int i = 0; i < rowNum; i++){
		for (int j = 0; j < colNum; j++){
			_copy.set(i, j, get(i, j) * f);
		}
	}
	return _copy;
}
Matrix Matrix::operator *(const Matrix& m){
	if (colNum != m.rowNum){
		cout << "无法相乘！";
		return *this;
	}
	Matrix _copy(rowNum, m.getColNum());
	for (int i = 0; i < rowNum; i++){
		for (int j = 0; j < m.colNum; j++){
			double sum = 0;
			for (int k = 0; k < m.rowNum; k++){
				sum += get(i, k) * m.get(k, j);
			}
			_copy.set(i, j, sum);
		}
	}
	return _copy;
}