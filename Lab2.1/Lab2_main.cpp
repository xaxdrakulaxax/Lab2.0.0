#include <iostream>

#include "Matrix.h"

using namespace std;

void rj_P_ri(Matrix &data , int i , int j, double mod_i , double mod_j)
{
	if (mod_i == 0) mod_i++;
	for (int q = 0; q < data.x_size; q++)
	{
		data.matrix[j][q] += mod_j * (data.matrix[i][q] / mod_i);
	}
}

void M_Gaus(Matrix data)
{
	if (data.x_size-1 > data.y_size)
	{
		cout << "Infened number of colutions" << endl;
		return;
	}
	for (int i = 0; i < data.x_size-2; i++)
	{
		for (int j = i+1; j < data.y_size; j++)
		{
			rj_P_ri(data, i, j, data.matrix[i][i], (-1)*data.matrix[j][i]);
		}
	}
	if (data.x_size - 1 < data.y_size)
	{
		for (int i = data.x_size - 2; i < data.y_size-1; i++)
		{
			if ((data.matrix[i][data.x_size - 1] / data.matrix[i][data.x_size - 2]) != (data.matrix[i + 1][data.x_size - 1] / data.matrix[i + 1][data.x_size - 2]))
			{
				cout<<"Matrix has no colutions"<<endl;
				return;
			}
		}
	}
	for (int i = data.x_size - 2; i >0; i--)
	{
		for (int j = i-1; j >=0; j--)
		{
			rj_P_ri(data, i, j, data.matrix[i][i], (-1)*data.matrix[j][i]);
		}
	}
	for (int i = 0; i < data.x_size - 1; i++)
	{
		if (data.matrix[i][data.x_size - 1] != 0 && data.matrix[i][i] == 0)
		{
			cout << "Matrix has no colutions" << endl;
			return;
		}
			
	}
	for (int i = 0; i < data.x_size-1; i++)
	{
		if (data.matrix[i][data.x_size - 1] == 0 && data.matrix[i][i] == 0)
		{
			cout << "x" << i + 1 << " = 0" << endl;
		}
		cout << "x" << i + 1 << " = " << data.matrix[i][data.x_size - 1] / data.matrix[i][i] << endl;
	}
}


void M_Cach(Matrix Koef, Matrix Eqv)
{
	if (Koef.x_size != Koef.y_size)
	{
		cout << "I can't do M_cach Metod(not equal size)" << endl;
		return;
	}
	Matrix temp(Koef.x_size, Koef.y_size);
	for (int i = 0; i < Koef.x_size; i++)
	{
		temp.matrix[i][i] = 1;
	}
	for (int i = 0; i < Koef.x_size - 1; i++)
	{
		for (int j = i + 1; j < Koef.y_size; j++)
		{
			rj_P_ri(Koef, i, j, Koef.matrix[i][i], (-1)*Koef.matrix[j][i]);
			rj_P_ri(temp, i, j, Koef.matrix[i][i], (-1)*Koef.matrix[j][i]);
		}
	}
	for (int i = Koef.x_size - 1; i > 0; i--)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			rj_P_ri(Koef, i, j, Koef.matrix[i][i], (-1)*Koef.matrix[j][i]);
			rj_P_ri(temp, i, j, Koef.matrix[i][i], (-1)*Koef.matrix[j][i]);
		}
	}
	for (int i = 0; i < Koef.x_size; i++)
	{
		for (int j = 0; j < Koef.y_size; j++)
		{
			temp.matrix[i][j] = temp.matrix[i][j] / Koef.matrix[i][i];
		}
	}

	Matrix x = (temp * Eqv);

	for (int i = 0; i < x.y_size; i++)
	{
		cout << "x" << i + 1 << " = " << x.matrix[i][1] << endl;
	}
}


int main()
{
	int choise = 0;
	cout << "Choise one of mathods:" << endl;
	cout << "1-Gaus" << endl;
	//cout << "2-Kachmag" << endl;
	cin >> choise;
	int x;
	cin >> x;
	int y;
	cin >> y;
	
	if (choise == 1)
	{
		Matrix m1(x, y);
		Matrix m2(x, 1);
		for (int i = 0; i < m1.y_size; i++)
		{
			for (int j = 0; j < m1.x_size; j++)
			{
				cin >> m1.matrix[i][j];
			}
		}
		M_Gaus(m1);
	}
	/*if (choise == 2)
	{
		Matrix m1(x-1, y);
		Matrix m2(x-1, 1);
		/*for (int i = 0; i < m1.y_size; i++)
		{
			for (int j = 0; j < m1.x_size; j++)
			{
				cin >> m1.matrix[i][j];
			}
			cin >> m2.matrix[1][i];
		}
		cout << m1.x_size << " " << m1.y_size;
		M_Cach(m1, m2);
	}*/
	system("pause");

	return 0;
}