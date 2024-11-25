#include <stdio.h>
#include <stdlib.h>

// Structure to represent an item
typedef struct {
    int value;
    int weight;
} Item;

// Function to compare items by value-to-weight ratio (for greedy approach)
int compare(const void* a, const void* b) {
    double r1 = (double)((Item*)a)->value / ((Item*)a)->weight;
    double r2 = (double)((Item*)b)->value / ((Item*)b)->weight;
    return (r1 < r2) - (r1 > r2); // Descending order
}

// Greedy Approach
int greedyKnapsack(Item items[], int n, int W) {
    qsort(items, n, sizeof(Item), compare); // Sort items by value-to-weight ratio
    int totalValue = 0, remainingWeight = W;

    for (int i = 0; i < n; i++) {
        if (items[i].weight <= remainingWeight) {
            totalValue += items[i].value;    // Include the item
            remainingWeight -= items[i].weight;
        }
    }

    return totalValue;
}

// Dynamic Programming Approach
int dpKnapsack(Item items[], int n, int W) {
    int dp[n + 1][W + 1];

    // Initialize DP table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (items[i - 1].weight <= w)
                dp[i][w] = 
                  (items[i - 1].value + dp[i - 1][w - items[i - 1].weight] > dp[i - 1][w])
                  ? items[i - 1].value + dp[i - 1][w - items[i - 1].weight] : dp[i - 1][w];
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[n][W];
}

int main() {
    // Example dataset
    int n = 4;                 // Number of items
    int W = 50;                // Knapsack capacity
    Item items[] = { 
        {60, 10},              // value, weight
        {100, 20},
        {120, 30},
        {40, 40}
    };

    // Solve using Greedy Approach
    int greedyResult = greedyKnapsack(items, n, W);
    printf("Greedy Approach Result: %d\n", greedyResult);

    // Solve using Dynamic Programming Approach
    int dpResult = dpKnapsack(items, n, W);
    printf("Dynamic Programming Result: %d\n", dpResult);

    return 0;
}
