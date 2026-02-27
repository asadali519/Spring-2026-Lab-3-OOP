//Asad Ali
//25l-0519

# include <iostream>
using namespace std;

int** createGrid(int rows, int cols);
void inputGrid(int** grid, int rows, int cols);
void displayGrid(int** grid, int rows, int cols);
void deleteGrid(int** grid, int rows);
void printHighValues(int** grid, int rows, int cols);


int main() {
    int rows = 0, cols = 0;
    cout << "Enter No. of Rows: ";
    cin >> rows;
    cout << "Enter No. of Columns: ";
    cin >> cols;

    int** grid = createGrid(rows, cols);

    inputGrid(grid, rows, cols);
    displayGrid(grid, rows, cols);
    printHighValues(grid, rows, cols);
    deleteGrid(grid, rows);

	return 0;
}

int** createGrid(int rows, int cols) {
    int** grid = new int* [rows];
    for (int i = 0; i < rows; i++) {
        *(grid + i) = new int[cols];
    }
    return grid;
}

void inputGrid(int** grid, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter Element [" << i + 1 << "][ " << j + 1 << "]: ";
            cin >> *(*(grid + i) + j);
        }
    }

    return;
}

void displayGrid(int** grid, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << *(*(grid + i) + j) << " ";
        }
        cout << endl;
    }
}

void printHighValues(int**grid, int rows, int cols) {
    

        cout << "High-value cells are:\n";
        bool found = false;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int val = *(*(grid + i) + j);
                bool isHigh = true;

                if (j > 0 && val < *(*(grid + i) + (j - 1)))
                    isHigh = false;
                if (j < cols - 1 && val < *(*(grid + i) + (j + 1)))
                    isHigh = false;

                if (isHigh) {
                    cout << "[" << i + 1 << "][" << j + 1 << "] = " << val << "\n";
                    found = true;
                }
            }
        }
        if (!found)
            cout << "None found.\n";

        return;
    }

void deleteGrid(int** grid, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] grid[i];
    }
    delete[] grid;
}