#include <stdio.h>

// Function to solve fractional knapsack
double fractionalKnapsack(int capacity, int weight[], int value[], int n) {
double total = 0.0;                    // Total value collected
int cap = capacity;                   // Remaining capacity

// Bubble sort items by value/weight ratio (descending)
for (int i = 0; i < n-1; i++) {
for (int j = 0; j < n-i-1; j++) {
double ratio1 = (double)value[j] / weight[j];
double ratio2 = (double)value[j+1] / weight[j+1];
if (ratio1 < ratio2) {



// Swap weights
int temp_w = weight[j];
weight[j] = weight[j+1];
weight[j+1] = temp_w;

// Swap values
int temp_v = value[j];
value[j] = value[j+1];
value[j+1] = temp_v;
}
} }

// Greedy selection: take highest ratio items first
for (int i = 0; i < n && cap > 0; i++) {
if (weight[i] <= cap) {

// Take whole item if it fits
total += value[i];
cap -= weight[i];
} else {

// Take fraction of item (partial amount)
double fraction = (double)cap / weight[i];
total += value[i] * fraction;
cap = 0;                   // Knapsack is now full
}
}
return total;             // Maximum achievable value
}

int main() {
// Example: Items (weight, value)
int weight[] = {5, 25, 30};
int value[] = {70, 100, 120};
int capacity = 50;
int n = 3;
double max_value = fractionalKnapsack(capacity, weight, value, n);
printf("Maximum value in knapsack: %.2f\n", max_value);
return 0;
}
