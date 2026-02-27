//Asad Ali
//25L-0519


#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

bool** createGrid(int rows, int cols);
void fillGrid(bool** grid, int rows, int cols);
void displayGrid(bool** grid, int rows, int cols);
void deleteGrid(bool** grid, int rows);
void countSensors(bool** grid, int rows, int cols);

int main() {
   srand(time(0));
   int rows = 0, cols = 0;
   cout << "Enter No. of Rows: ";
   cin >> rows;
   cout << "Enter No. of Columns: ";
   cin >> cols;

   bool** grid = createGrid(rows, cols);

   fillGrid(grid, rows, cols);
   displayGrid(grid, rows, cols);

   countSensors(grid, rows, cols);

   deleteGrid(grid, rows);

   return 0;
}

bool** createGrid(int rows, int cols) {
   bool** grid = new bool* [rows];
   for (int i = 0; i < rows; i++) {
       *(grid + i) = new bool[cols];
   }
   return grid;
}

void fillGrid(bool** grid, int rows, int cols) {
   for (int i = 0; i < rows; i++) {
       for (int j = 0; j < cols; j++) {
           *(*(grid + i) + j) = rand() % 2;
       }
   }
}

void displayGrid(bool** grid, int rows, int cols) {
   for (int i = 0; i < rows; i++) {
       for (int j = 0; j < cols; j++) {
           cout << *(*(grid + i) + j) << " ";
       }
       cout << endl;
   }
}

void deleteGrid(bool** grid, int rows) {
   for (int i = 0; i < rows; i++) {
       delete[] grid[i];
   }
   delete[] grid;
}

void countSensors(bool** grid, int rows, int cols) {


   for (int j = 0; j < cols; j++) {
       int count = 0;
       for (int i = 0; i < rows; i++) {
           if (*(*(grid + i) + j)) count++;
       }
       cout << "Sensors in Column " << j + 1 << " are " << count << endl;
   }

   return;
}