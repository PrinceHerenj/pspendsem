#include <iostream>
using namespace std;

void sortRow(char* row, int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (row[i] > row[j]) {
                char temp = row[i];
                row[i] = row[j];
                row[j] = temp;
            }
        }
    }
}

int main() {
    int rows;
    cout << "Enter the number of rows: ";
    cin >> rows;

    // Allocate memory for the ragged array
    char** arr = new char*[rows];
    int* lengths = new int[rows];
    int maxCols = 0;

    // Input and sort each row
    for (int i = 0; i < rows; i++) {
        cout << "Enter the number of characters in row " << i + 1 << ": ";
        cin >> lengths[i];
        arr[i] = new char[lengths[i]];

        cout << "Enter characters for row " << i + 1 << ": ";
        for (int j = 0; j < lengths[i]; j++) {
            cin >> arr[i][j];
        }

        // Sort the row and update the maximum column count if necessary
        sortRow(arr[i], lengths[i]);
        if (lengths[i] > maxCols) {
            maxCols = lengths[i];
        }
    }

    // Display the transpose
    cout << "\nTransposed Array:\n";
    for (int col = 0; col < maxCols; col++) {
        for (int row = 0; row < rows; row++) {
            if (col < lengths[row]) {
                cout << arr[row][col] << " ";
            } else {
                cout << "  ";
            }
        }
        cout << endl;
    }

    // Free allocated memory
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    delete[] lengths;


}