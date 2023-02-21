#include<iostream>
#include"function.h"
Matrix::~Matrix()
{
 	
}
Matrix::Matrix(int n):n(n)
{
	matrix = new long long* [n];
	for(int i = 0; i < n; i++)
	{
		matrix[i] = new long long [n];
	}
	toZero();
}
 
   // TODO: Copy contructor
  // Will be trigger when the following condition:
  // Matrix m = ref; -> Call copy contructor to copy from 'ref' to 'm'
Matrix::Matrix(const Matrix& ref)
{
	n = ref.n;
	matrix = new long long* [n];
	for(int i = 0; i < n; i++)
	{
		matrix[i] = new long long [n];
	}
	matrix = ref.matrix;
}

  // TODO: copy assignment,
  // Will be trigger when the following condition:
  // Matrix a;
  // a = ref; -> Call copy assignment to copy from 'ref' to 'a'
Matrix& Matrix::operator=(const Matrix& ref)
{
	n = ref.n;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			matrix[i][j] = ref.matrix[i][j];
		}
	}
	return *this;///////////
}


 // TODO: Overload operator()
  // This operator allow the following code
  // This operator can help you access the data easily
  // 1. cout << m(1, 2) << endl; -> Shorthand of `cout << m.matrix[1, 2] << endl;`
  // 2. m(1, 2) = 100; -> Shorthand of `m.matrix[1, 2] = 100`
long long& Matrix::operator()(const int& row, const int& column) const
{
	return matrix[row][column];
}

  // TODO: Make the matrix identity matrix
void Matrix::toIdentity()
{
	for(int i = 0; i < n-1; i++)
	{
		matrix[i][i+1] = 1;
	}
	for(int i = 0; i < n; i++)
	{
		matrix[n-1][i] = 1;
	}
	
}

  // TODO: Overload operator * 
Matrix Matrix::operator*(const Matrix& rhs) const
{
	Matrix total(n);
	total.toZero();
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			for(int k = 0; k < n; k++)
			{
				total(i, j) += ((*this)(i, k) * rhs(k, j)) % mod;
				total(i, j) %= mod;
			}
		}
	}
	return total;
}

// TODO: Return the matrix power of 'k'
Matrix Matrix::power(int k) const
{
	Matrix tmp(n);
	tmp = *this;
	if(k == 1) return tmp;
	if(k % 2 == 1)
	{
		tmp = power((k-1) / 2);
		return tmp * tmp * (*this);
	}
	else
	{
		tmp = power(k / 2);
		return tmp * tmp;
	}
}

Matrix constructMatrix(int n)
{
	Matrix ans(n);
	ans.toIdentity();
	return ans;
	
}
