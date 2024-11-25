#include <stdio.h>
#include <limits.h>

// Function to find the minimum number of multiplications
void matrixChainMultiplication(int p[], int n) {
    int m[n][n]; // Cost matrix
    int s[n][n]; // Store k for optimal split

    // Initialize cost matrix
    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    // L is the chain length
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (cost < m[i][j]) {
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }

    printf("Minimum number of multiplications: %d\n", m[1][n - 1]);
    printf("Optimal Parenthesization: ");
    printOptimalParenthesis(s, 1, n - 1);
    printf("\n");
}

// Function to print the optimal parenthesization
void printOptimalParenthesis(int s[][10], int i, int j) {
    if (i == j) {
        printf("A%d", i);
    } else {
        printf("(");
        printOptimalParenthesis(s, i, s[i][j]);
        printOptimalParenthesis(s, s[i][j] + 1, j);
        printf(")");
    }
}

int main() {
    // Matrix dimensions: A1 (30x35), A2 (35x15), A3 (15x5), A4 (5x10), A5 (10x20), A6 (20x25)
    int p[] = {30, 35, 15, 5, 10, 20, 25};
    int n = sizeof(p) / sizeof(p[0]);

    matrixChainMultiplication(p, n);
    return 0;
}
