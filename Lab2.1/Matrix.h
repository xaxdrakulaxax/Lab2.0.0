#pragma once
class Matrix
{
public:
	Matrix operator =(Matrix & data);

	bool operator ==(Matrix & data);

	Matrix operator +(Matrix & data);

	Matrix operator +(double data);

	Matrix operator -(Matrix & data);

	Matrix operator -(double data);

	Matrix operator *(Matrix & data);

	Matrix operator *(double data);

	Matrix operator <<(Matrix & data);

	Matrix operator >>(Matrix & data);

	Matrix operator ~();

private:
	static const int x_size = 10;
	static const int y_size = 10;

	int matrix[x_size][y_size];
};

