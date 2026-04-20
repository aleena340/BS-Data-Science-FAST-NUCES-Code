#include<iostream>
using namespace std;

// Helper function to print a line with appropriate characters
void printLine(int stars, int spaces,int totalStars) {
    if (stars > 0) {
        cout << "*";
        printLine(stars - 1, spaces,totalStars);
    } else if (spaces > 0) {
        cout << " ";
        printLine(stars, spaces - 1,totalStars);
    } 
    else if (totalStars>=stars){
        cout << "*";
        printLine(stars, spaces,totalStars-1);
    }
    else {
        cout << endl;
    }
}

// Recursive function to print the upper half of the diamond
void printUpperHalf(int n, int row) {
    if (row <= n) {
        printLine(n - row + 1, row - 1 , n - row + 1);
        printUpperHalf(n, row + 1);
    }
}

// Recursive function to print the lower half of the diamond (inverted triangle)
void printLowerHalf(int n, int row) {
    if (row >= 1) {
        printLine(n - row + 1, row - 1, n - row + 1);
        printLowerHalf(n, row - 1);
    }
}

// Main function to print the diamond pattern
void hollowDiamondPattern(int n) {
    if (n % 2 == 0) {
        n++; // Ensure odd number
    }
    
    cout << "Diamond pattern for " << n << " is:\n";

    // Print upper half
    printUpperHalf(n / 2 + 1, 1);

    // Print lower half (inverted triangle)
    printLowerHalf(n / 2, n / 2);
}

int main() {
    int n;
    cout << "Enter the size of the pattern (odd number): ";
    cin >> n;
    hollowDiamondPattern(n);
    return 0;
}
