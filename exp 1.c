#include <stdio.h>

typedef struct {
    int start, finish;
} Activity;

// Sort activities by finish time
void sortActivities(Activity activities[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (activities[j].finish > activities[j + 1].finish) {
                Activity temp = activities[j];
                activities[j] = activities[j + 1];
                activities[j + 1] = temp;
            }
}

void activitySelection(Activity activities[], int n) {
    sortActivities(activities, n); // Step 1: Sort by finish time
    printf("Selected activities:\n");

    // Step 2: Select the first activity
    int lastFinish = activities[0].finish;
    printf("(%d, %d)\n", activities[0].start, activities[0].finish);

    // Step 3: Select remaining non-overlapping activities
    for (int i = 1; i < n; i++) {
        if (activities[i].start >= lastFinish) {
            printf("(%d, %d)\n", activities[i].start, activities[i].finish);
            lastFinish = activities[i].finish;
        }
    }
}

int main() {
    Activity activities[] = { {1, 3}, {2, 4}, {3, 5}, {0, 6}, {5, 7}, {8, 9}, {5, 9} };
    int n = sizeof(activities) / sizeof(activities[0]);
    activitySelection(activities, n);
    return 0;
}
