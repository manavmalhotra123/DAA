#include <iostream>

using namespace std;

// Structure to represent an item
struct Item {
    int weight;
    int value;
};

// Function to calculate the upper bound value for a node
int upperBound(int capacity, int weight, int value, Item items[], int n) {
    int totalWeight = weight;
    int totalValue = value;
    int i = n;

    // Add items until the capacity is exceeded
    while (i < n && totalWeight + items[i].weight <= capacity) {
        totalWeight += items[i].weight;
        totalValue += items[i].value;
        i++;
    }

    // If the capacity is not fully utilized, calculate the upper bound
    if (i < n) {
        totalValue += (capacity - totalWeight) * items[i].value / items[i].weight;
    }

    return totalValue;
}

// Function to perform branch and bound recursively
void branchAndBound(int capacity, int weight, int value, Item items[], int n, int &maxValue) {
    // Base case: if all items are considered or capacity becomes 0
    if (n == 0 || capacity == 0) {
        if (value > maxValue) {
            maxValue = value;
        }
        return;
    }

    // Calculate the upper bound
    int bound = upperBound(capacity, weight, value, items, n);

    // If the upper bound is less than the current maximum value, stop exploring this node
    if (bound <= maxValue) {
        return;
    }

    // Explore left subtree (exclude current item)
    branchAndBound(capacity, weight, value, items, n - 1, maxValue);

    // Explore right subtree (include current item)
    if (capacity >= items[n - 1].weight) {
        branchAndBound(capacity - items[n - 1].weight,
                       weight + items[n - 1].weight,
                       value + items[n - 1].value,
                       items, n - 1, maxValue);
    }
}

int main() {
    int capacity = 10;
    Item items[] = {{5, 10}, {8, 7}, {3, 5}, {2, 3}};
    int n = sizeof(items) / sizeof(items[0]);
    int maxValue = 0;

    branchAndBound(capacity, 0, 0, items, n, maxValue);

    cout << "The maximum value that can be obtained: " << maxValue << endl;

    return 0;
}
