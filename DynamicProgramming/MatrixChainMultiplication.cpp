#include <iostream>

const int MAX = 1000; // Maximum value for demonstration purposes

int matrixChainOrder(int p[], int n) {
    int dp[n][n];
    
    // Initialize the dp table
    for (int i = 1; i < n; i++)
        dp[i][i] = 0;
    
    for (int len = 2; len < n; len++) {
        for (int i = 1; i < n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = MAX; // Set to a large value
            
            for (int k = i; k <= j - 1; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (cost < dp[i][j])
                    dp[i][j] = cost;
            }
        }
    }
    
    return dp[1][n - 1];
}

int main() {
    int arr[] = {5, 4, 6, 2, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int result = matrixChainOrder(arr, n);
    
    std::cout << "Minimum number of multiplications: " << result << std::endl;
    
    return 0;
}
