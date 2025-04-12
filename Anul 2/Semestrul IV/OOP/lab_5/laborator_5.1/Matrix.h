#pragma once
#include <iostream>

using namespace std;

class Matrix
{
	private:
		double** matrix;
		int rows;
		int columns;
	public:
		Matrix()
		{
			rows = 0;
			columns = 0;
			matrix = nullptr;
		}
		Matrix(int rows, int columns)
		{
			this->rows = rows;
			this->columns = columns;
			matrix = new double* [rows];
			for (int i = 0; i < rows; i++)
			{
				matrix[i] = new double[columns];
			}
		}
		Matrix(int p)
		{
			rows = p;
			columns = p;
			matrix = new double* [rows];
			for (int i = 0; i < rows; i++)
			{
				matrix[i] = new double[columns];
			}
		}
		~Matrix()
		{
			for (int i = 0; i < rows; i++)
			{
				delete[] matrix[i];
			}
			delete[] matrix;
		}
		void set(int i, int j, double value)
		{
			matrix[i][j] = value;
		}
		double get(int i, int j)
		{
			return matrix[i][j];
		}
		int getRows()
		{
			return rows;
		}
		int getColumns()
		{
			return columns;
		}
		void print()
		{
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < columns; j++)
				{
					cout << matrix[i][j] << " ";
				}
				cout << endl;
			}
		}
		Matrix operator+(Matrix& m)
		{
			if (rows != m.getRows() || columns != m.getColumns())
			{
				throw invalid_argument("Matricele nu pot fi adunate!");
			}
			else
			{
				Matrix result(rows, columns);
				for (int i = 0; i < rows; i++)
				{
					for (int j = 0; j < columns; j++)
					{
						result.set(i, j, matrix[i][j] + m.get(i, j));
					}
				}
				return result;
			}
		}
		Matrix operator-(Matrix& m)
		{
			if (rows != m.getRows() || columns != m.getColumns())
			{
				throw invalid_argument("Matricele nu pot fi adunate!");
			}
			else
			{
				Matrix result(rows, columns);
				for (int i = 0; i < rows; i++)
				{
					for (int j = 0; j < columns; j++)
					{
						result.set(i, j, matrix[i][j] - m.get(i, j));
					}
				}
				return result;
			}
		}
		Matrix operator*(Matrix& m)
		{
			if (columns != m.getRows())
			{
				throw invalid_argument("Matricele nu pot fi inmultite!");
			}
			else
			{
				Matrix result(rows, m.getColumns());
				for (int i = 0; i < rows; i++)
				{
					for (int j = 0; j < m.getColumns(); j++)
					{
						double sum = 0;
						for (int k = 0; k < columns; k++)
						{
							sum += matrix[i][k] * m.get(k, j);
						}
						result.set(i, j, sum);
					}
				}
				return result;
			}
		}
		Matrix operator*(double d)
		{
			Matrix result(rows, columns);
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < columns; j++)
				{
					result.set(i, j, matrix[i][j] * d);
				}
			}
			return result;
		}
};

