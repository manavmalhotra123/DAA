#include <iostream>

using namespace std;

bool isSubsetSum(int values[], int size, int target) {
    if (target == 0) {
        return true;
    }
    if (size == 0 || target < 0) {
        return false;
    }

    // If the current element is greater than the target, skip it
    if (values[size - 1] > target) {
        return isSubsetSum(values, size - 1, target);
    }

    // Check if either including the current element or excluding it leads to a solution
    return isSubsetSum(values, size - 1, target) ||
           isSubsetSum(values, size - 1, target - values[size - 1]);
}

void solveSubsetSum(int values[], int size, int target) {
    if (isSubsetSum(values, size, target)) {
        cout << "Subset that sums up to target " << target << " is: ";
        for (int i = 0; i < size; ++i) {
            if (values[i] <= target) {
                cout << values[i] << " ";
                target -= values[i];
            }
        }
        cout << endl;
    } else {
        cout << "No subset found that sums up to target " << target << endl;
    }
}

int main() {
    int values[] = {11, 13, 24, 7};
    int size = sizeof(values) / sizeof(values[0]);
    int target = 31;

    solveSubsetSum(values, size, target);
    return 0;
}
