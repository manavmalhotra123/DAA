#include<iostream>
#include<cstring> // Include for memset
using namespace std;

// Recursive approach without memoization
int knapSackRecursive(int W, int wt[], int val[], int n) {
    if (n == 0 || W == 0)
        return 0;

    if (wt[n - 1] > W)
        return knapSackRecursive(W, wt, val, n - 1);

    else
        return max(val[n - 1] + knapSackRecursive(W - wt[n - 1], wt, val, n - 1),
                   knapSackRecursive(W, wt, val, n - 1));
}


// Dynamic Programming solution
int knapSackDP(int W, int wt[], int val[], int n) {
    int dp[n + 1][W + 1];

    memset(dp, -1, sizeof(dp));

    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int i = 0; i <= W; i++)
        dp[0][i] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            if (wt[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
        }
    }

    return dp[n][W];
}

int main() {
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);

    // Recursive solution without memoization
    cout << "Maximum value using recursive approach: " << knapSackRecursive(W, wt, val, n) << endl;

    // Dynamic Programming solution
    cout << "Maximum value using dynamic programming: " << knapSackDP(W, wt, val, n) << endl;

    return 0;
}
