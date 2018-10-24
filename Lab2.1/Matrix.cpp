#include "Matrix.h"

#include <iostream>

using namespace std;

Matrix Matrix::operator =(Matrix & data)
{
	
	for (int i = 0; i < x_size; i++)
	{
		for (int j = 0; j < y_size; j++)
		{
			this->matrix[i][j] = data.matrix[i][j];
		}
	}
}

bool Matrix::operator ==(Matrix & data)
{

}

Matrix Matrix::operator +(Matrix & data)
{

}

Matrix Matrix::operator +(double data)
{

}

Matrix Matrix::operator -(Matrix & data)
{

}

Matrix Matrix::operator -(double data)
{

}

Matrix Matrix::operator *(Matrix & data)
{

}

Matrix Matrix::operator *(double data)
{

}

Matrix Matrix::operator <<(Matrix & data)
{

}

Matrix Matrix::operator >>(Matrix & data)
{

}

Matrix Matrix::operator ~()
{

}

