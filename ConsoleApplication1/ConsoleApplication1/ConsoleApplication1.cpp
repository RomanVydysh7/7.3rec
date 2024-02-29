#include <iostream>
#include <iomanip>
#include <time.h>
#include <climits>
const int MAX_SIZE = 100;


int countColumnsWithZeroRecursive(int matrix[MAX_SIZE][MAX_SIZE], int k, int n, int j) {
    if (j == n) {
        return 0;
    }

    for (int i = 0; i < k; ++i) {
        if (matrix[i][j] == 0) {
            return 1 + countColumnsWithZeroRecursive(matrix, k, n, j + 1);
        }
    }

    return countColumnsWithZeroRecursive(matrix, k, n, j + 1);
}


int findRowWithLongestSeriesRecursive(int matrix[MAX_SIZE][MAX_SIZE], int k, int n, int i, int j,
    int currentSeriesLength, int& maxSeriesRow, int& maxSeriesLength) {
    if (i == k) {
        return maxSeriesRow;
    }   

    if (j == n) {
        if (currentSeriesLength > maxSeriesLength) {
            maxSeriesLength = currentSeriesLength;
            maxSeriesRow = i;
        }
        return findRowWithLongestSeriesRecursive(matrix, k, n, i + 1, 0, 1, maxSeriesRow, maxSeriesLength);
    }

    if (j > 0 && matrix[i][j] == matrix[i][j - 1]) {
        return findRowWithLongestSeriesRecursive(matrix, k, n, i, j + 1, currentSeriesLength + 1, maxSeriesRow, maxSeriesLength);
    }
    else {
        return findRowWithLongestSeriesRecursive(matrix, k, n, i, j + 1, 1, maxSeriesRow, maxSeriesLength);
    }
}

int main() {
    int matrix[MAX_SIZE][MAX_SIZE];
    int k, n;


    std::cout << "k: ";
    std::cin >> k;

    std::cout << "n: ";
    std::cin >> n;


    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << "a[" << i << "][" << j << "] = ";
            std::cin >> matrix[i][j];
        }
    }


    std::cout << "Number of columns with at least one null element: "
        << countColumnsWithZeroRecursive(matrix, k, n, 0) << std::endl;

    int maxSeriesRow = -1;
    int maxSeriesLength = 0;

    int result = findRowWithLongestSeriesRecursive(matrix, k, n, 0, 0, 1, maxSeriesRow, maxSeriesLength);

    if (result != -1) {
        std::cout << "Row number with the largest series of identical elements: " << result + 1 << std::endl;
    }
    else {
        std::cout << "The matrix does not contain a series of identical elements." << std::endl;
    }

    return 0;   
}