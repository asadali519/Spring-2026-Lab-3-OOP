//Asad Ali
//25-0519


#include<iostream>
using namespace std;

void deleteGrid(int** grid, int rows);

int main()
{
	int rows, cols;

	cout << "Enter number of rows: ";
	cin >> rows;
	cout << "Enter number of columns: ";
	cin >> cols;

	while (rows != cols)
	{
		cout << "Invalid input! Number of rows and columns should be same. Enter again" << endl;
		cout << "Enter number of rows: ";
		cin >> rows;
		cout << "Enter number of columns: ";
		cin >> cols;
	}

	int** grid = nullptr;
	grid = new int* [rows];

	for (int i = 0; i < rows; i++)
	{
		grid[i] = new int[cols];
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << "Enter Element [" << i + 1 << "][ " << j + 1 << "]: ";
			cin >> *(*(grid + i) + j);
		}
	}

	cout << "\nMatrix : " << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << *(*(grid + i) + j) << " ";
		}
		cout << endl;
	}

	cout << "\nDiagonal elements: ";
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (i == j)
			{
				cout << *(*(grid + i) + j) << " ";
			}
		}
	}
	cout << endl;

	deleteGrid(grid, rows);

	return 0;
}

void deleteGrid(int** grid, int rows) {
	for (int i = 0; i < rows; i++) {
		delete[] grid[i];
	}
	delete[] grid;
}