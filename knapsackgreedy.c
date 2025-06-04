#include <stdio.h>
#define MAX_ITEMS 50

// Function to solve 0/1 Knapsack Problem (Discrete)
void solveDiscreteKnapsack(float weight[], float profit[], int n, float capacity) {
    float ratio[MAX_ITEMS], totalValue = 0;

    // Calculate profit-to-weight ratio for each item
    for (int i = 0; i < n; i++)
        ratio[i] = profit[i] / weight[i];

    // Sort items by ratio in descending order (Greedy approach)
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                // Swap ratios
                float temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;

                // Swap corresponding weights
                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;

                // Swap corresponding profits
                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;
            }
        }
    }

    // Fill the knapsack (Discrete: either take full item or none)
    for (int i = 0; i < n && capacity > 0; i++) {
        if (weight[i] <= capacity) {
            totalValue += profit[i];     // Add full item
            capacity -= weight[i];
        }
    }

    printf("Maximum value for 0/1 knapsack problem: %.2f\n", totalValue);
}

// Function to solve Fractional (Continuous) Knapsack
void solveContinuousKnapsack(float weight[], float profit[], int n, float capacity) {
    float ratio[MAX_ITEMS], totalValue = 0;

    // Calculate profit-to-weight ratio for each item
    for (int i = 0; i < n; i++)
        ratio[i] = profit[i] / weight[i];

    // Sort items by ratio in descending order
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                float temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;

                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;

                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;
            }
        }
    }

    // Fill the knapsack (Fractional: take part of item if needed)
    for (int i = 0; i < n && capacity > 0; i++) {
        if (weight[i] <= capacity) {
            totalValue += profit[i];  // Take full item
            capacity -= weight[i];
        } else {
            // Take a fraction of the item
            totalValue += ratio[i] * capacity;
            break;
        }
    }

    printf("Maximum value for continuous knapsack problem: %.2f\n", totalValue);
}

int main() {
    int n;
    float capacity;
    float weight[MAX_ITEMS], profit[MAX_ITEMS];

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the weight and profit of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%f %f", &weight[i], &profit[i]);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%f", &capacity);

    // Solve both variations
    solveDiscreteKnapsack(weight, profit, n, capacity);
    solveContinuousKnapsack(weight, profit, n, capacity);

    return 0;
}
