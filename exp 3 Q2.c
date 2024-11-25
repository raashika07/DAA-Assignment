#include <stdio.h>
#include <limits.h>

#define MAX 100 // Define a sufficiently large size

// Function to print the optimal parenthesization
void printOptimalParenthesis(int i, int j, int s[MAX][MAX]) {
    if (i == j) {
        printf("A%d", i); // Print matrix name
    } else {
        printf("(");
        printOptimalParenthesis(i, s[i][j], s);        // Print left part
        printOptimalParenthesis(s[i][j] + 1, j, s);   // Print right part
        printf(")");
    }
}

// Function to find the minimum number of multiplications
void matrixChainMultiplication(int p[], int n) {
    int m[MAX][MAX]; // Minimum cost matrix
    int s[MAX][MAX]; // Matrix for storing split points

    // Initialize cost for single matrix chains
    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    // Fill the m and s tables for chain lengths L=2 to n-1
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX; // Set to infinity initially
            for (int k = i; k < j; k++) {
                // Compute cost of splitting at k
                int cost = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (cost < m[i][j]) {
                    m[i][j] = cost; // Update minimum cost
                    s[i][j] = k;    // Store the split point
                }
            }
        }
    }

    // Output results
    printf("Minimum number of multiplications: %d\n", m[1][n - 1]);
    printf("Optimal Parenthesization: ");
    printOptimalParenthesis(1, n - 1, s);
    printf("\n");
}

int main() {
    // Input dimensions for matrices A1, A2, ..., An
    // Example: A1 (30x35), A2 (35x15), A3 (15x5), A4 (5x10), A5 (10x20), A6 (20x25)
    int p[] = {30, 35, 15, 5, 10, 20, 25};
    int n = sizeof(p) / sizeof(p[0]); // Number of matrices = n - 1

    // Call the function
    matrixChainMultiplication(p, n);
    return 0;
}


