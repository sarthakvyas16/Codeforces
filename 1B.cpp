// B. Spreadsheets
// time limit per test10 seconds
// memory limit per test64 megabytes
// In the popular spreadsheets systems (for example, in Excel) the following numeration of columns is used. The first column has number A, the second — number B, etc. till column 26 that is marked by Z. Then there are two-letter numbers: column 27 has number AA, 28 — AB, column 52 is marked by AZ. After ZZ there follow three-letter numbers, etc.

// The rows are marked by integer numbers starting with 1. The cell name is the concatenation of the column and the row numbers. For example, BC23 is the name for the cell that is in column 55, row 23.

// Sometimes another numeration system is used: RXCY, where X and Y are integer numbers, showing the column and the row numbers respectfully. For instance, R23C55 is the cell from the previous example.

// Your task is to write a program that reads the given sequence of cell coordinates and produce each item written according to the rules of another numeration system.

// Input
// The first line of the input contains integer number n (1 ≤ n ≤ 105), the number of coordinates in the test. Then there follow n lines, each of them contains coordinates. All the coordinates are correct, there are no cells with the column and/or the row numbers larger than 106 .

// Output
// Write n lines, each line should contain a cell coordinates in the other numeration system.

// Examples
// InputCopy
// 2
// R23C55
// BC23
// OutputCopy
// BC23
// R23C55

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Convert column number to spreadsheet format
string columnToLetters(int columnNumber) {
    string result;
    while (columnNumber > 0) {
        columnNumber--; // Convert to zero-based index
        result = char('A' + (columnNumber % 26)) + result;
        columnNumber /= 26;
    }
    return result;
}

// Convert spreadsheet format to column number
int lettersToColumn(const string& columnLabel) {
    int columnNumber = 0;
    for (char c : columnLabel) {
        columnNumber = columnNumber * 26 + (c - 'A' + 1);
    }
    return columnNumber;
}

int main() {
    int n;
    cin >> n;
    cin.ignore(); // To ignore the newline after the integer input

    while (n--) {
        string coord;
        getline(cin, coord);

        if (coord[0] == 'R' && coord.find('C') != string::npos) {
            // RXCY format
            size_t pos = coord.find('C');
            int row = stoi(coord.substr(1, pos - 1));
            int column = stoi(coord.substr(pos + 1));
            cout << columnToLetters(column) << row << endl;
        } else {
            // Spreadsheet format
            size_t pos = 0;
            while (isalpha(coord[pos])) {
                pos++;
            }
            string columnLabel = coord.substr(0, pos);
            int row = stoi(coord.substr(pos));
            int column = lettersToColumn(columnLabel);
            cout << "R" << row << "C" << column << endl;
        }
    }

    return 0;
}

