#include<iostream>

using namespace std;

void supporter(int values[], int target, int start, int currentSet[], int result[], int &resultSize, int size) {
    if (target == 0) {
        resultSize = size;
        for (int i = 0; i < size; ++i) {
            result[i] = currentSet[i];
        }
        return;
    }

    if (start == size || target < 0) {
        return;
    }

    supporter(values, target, start + 1, currentSet, result, resultSize, size);

    currentSet[start] = values[start];
    supporter(values, target - values[start], start + 1, currentSet, result, resultSize, size);
    currentSet[start] = 0;
}

void solve(int values[], int size, int target) {
    int* result = new int[size];
    int* currentSet = new int[size];
    int resultSize = 0;

    int start = 0;
    supporter(values, target, start, currentSet, result, resultSize, size);

    if (resultSize > 0) {
        cout << "Subset that sums up to target " << target << " is: ";
        for (int i = 0; i < resultSize; ++i) {
            cout << result[i] << " ";
        }
        cout << endl;
    } else {
        cout << "No subset found that sums up to target " << target << endl;
    }

    delete[] result;
    delete[] currentSet;
}

int main() {
    int values[] = {11, 13, 24, 7};
    int size = sizeof(values) / sizeof(values[0]);
    int target = 31;

    solve(values, size, target);
    return 0;
}
