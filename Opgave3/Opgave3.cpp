#include <iostream>
#include <iomanip>
#include <vector>  

class Opgave3
{
    public: bool searchMatrix(const std::vector<int>& matrix, int m, int n, int x) {
        int row = 0;
        int col = n - 1;  // Start fra top højre

        while (row < m && col >= 0) {
            if (matrix[row * n + col] == x) {
            std::cout << "Located " << x << " at position (" << row << ", " << col << ")." << std::endl;
                return true;
            } 
            else if (matrix[row * n + col] > x) {
            // element større end X -> mod venstre
                col--;
            } else {
            // Element mindre end X -> nedad 
            row++;
        }
    }
        std::cout << x << " not found in the matrix." << std::endl;
        return false;
    }
};



int main() {
    Opgave3 opgave3;
    //Eksempel på værdier man kunne bruge...

    int m = 4; // Number of rows
    int n = 4; // Number of columns
    std::vector<int> sortedMatrix = {1, 4, 7, 11, 2, 5, 8, 12, 3, 6, 9, 16, 10, 13, 14, 17};

    int searchElement = 8;

    std::cout << "Searching for " << searchElement << " in the matrix:" << std::endl;
    opgave3.searchMatrix(sortedMatrix, m, n, searchElement);

    //vigtigt husk der tælles fra 0 
    // 1  4  7  11
    // 2  5  8  12
    // 3  6  9  16
    // 10 13 14 17
}
