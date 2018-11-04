#include "Matrix.h"

#include <iostream>

using namespace std;


Matrix::Matrix(int xs , int ys)
{
	x_size = xs;

	y_size = ys;

}


Matrix Matrix::operator =(Matrix & data)
{
	this->x_size = data.x_size;
	this->y_size = data.y_size;
	
	for (int i = 0; i < x_size; i++)
	{
		for (int j = 0; j < y_size; j++)
		{
			this->matrix[i][j] = data.matrix[i][j];
		}
	}
	return *this;
}

bool Matrix::operator ==(Matrix & data)
{
	for (int i = 0; i < x_size; i++)
	{
		for (int j = 0; j < y_size; j++)
		{
			if (this->matrix[i][j] != data.matrix[i][j]) return false;
		}
	}
	return true;
}

Matrix Matrix::operator +(Matrix data)
{
	if ((this->x_size != data.x_size) || (this->y_size != data.y_size))
	{
		cout << "it's impossible to add matrix" << endl;
	}
	Matrix temp(this->x_size, this->y_size);
	for (int i = 0; i < x_size; i++)
	{
		for (int j = 0; j < y_size; j++)
		{
			temp.matrix[i][j] += data.matrix[i][j];
		}
	}
	return temp;
}

Matrix Matrix::operator -(Matrix & data)
{
	if ((this->x_size != data.x_size) || (this->y_size != data.y_size))
	{
		cout << "it's impossible to add matrix" << endl;
	}
	Matrix temp(this->x_size, this->y_size);
	for (int i = 0; i < x_size; i++)
	{
		for (int j = 0; j < y_size; j++)
		{
			temp.matrix[i][j] -= data.matrix[i][j];
		}
	}
	return temp;
}

void Matrix::operator *(double data)
{
	for (int i = 0; i < x_size; i++)
	{
		for (int j = 0; j < y_size; j++)
		{
			this->matrix[i][j] *=data;
		}
	}
}

Matrix Matrix::operator *(Matrix & data)
{
	if (this->y_size  != data.x_size)
	{
		cout << "it's impossible to multiply matrix" << endl;
	}
	Matrix temp(this->x_size , data.y_size);
	for (int i = 0; i < this->x_size; i++)
	{
		for (int j = 0; j < data.y_size; j++)
		{
			for (int q = 0; q < data.x_size; q++)
			{
				temp.matrix[i][j] += this->matrix[i][q] * data.matrix[q][j];
			}
		}
	}
	return temp;

}

void Matrix::operator <<(Matrix  &data)
{
	cout << "****************************************************" << endl;
	for (int i = 0; i < y_size; i++)
	{
		for (int j = 0; j < x_size; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << "****************************************************" << endl;
}

void Matrix::operator >>(Matrix  &data)
{
	for (int i = 0; i < y_size; i++)
	{
		for (int j = 0; j < x_size; j++)
		{
			cin >> matrix[i][j];
		}
	}
}

Matrix Matrix::operator ~()
{
	Matrix temp(y_size, x_size);
	for (int i = 0; i < x_size; i++)
	{
		for (int j = 0; j < y_size; j++)
		{
			temp.matrix[j][i] -= this->matrix[i][j];
		}
	}
	return temp;
}

