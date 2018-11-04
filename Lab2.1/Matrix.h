#pragma once
class Matrix
{
public:
	int x_size;
	int y_size;

	double matrix[10][10];
	Matrix()=default;

	Matrix(int xs , int ys);

	Matrix operator =(Matrix & data);

	bool operator ==(Matrix & data);

	Matrix operator +(Matrix data);

	Matrix operator -(Matrix & data);

	void operator *(double data);

	Matrix operator *(Matrix & data);

	void operator <<(Matrix  &data);

	void operator >>(Matrix  &data);

	Matrix operator ~();

private:

};

