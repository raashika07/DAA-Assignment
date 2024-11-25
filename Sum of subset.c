#include <stdio.h>

void subsetSum(int set[], int n, int target, int subset[], int subsetSize, int sum, int index) {
    if (sum == target) {
        printf("Subset: ");
        for (int i = 0; i < subsetSize; i++) {
            printf("%d ", subset[i]);
        }
        printf("\n");
        return;
    }

    if (index >= n || sum > target) {
        return;
    }

    // Include the current element
    subset[subsetSize] = set[index];
    subsetSum(set, n, target, subset, subsetSize + 1, sum + set[index], index + 1);

    // Exclude the current element
    subsetSum(set, n, target, subset, subsetSize, sum, index + 1);
}

int main() {
    int set[] = {10, 7, 5, 18, 12, 20, 15};
    int n = sizeof(set) / sizeof(set[0]);
    int target = 35;

    int subset[n];
    printf("Subsets that sum to %d:\n", target);
    subsetSum(set, n, target, subset, 0, 0, 0);

    return 0;
}
