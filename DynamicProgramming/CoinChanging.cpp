#include<iostream>
#include<vector>
#include<climits>

using namespace std;

// Recursive approach
int RecursiveMinCoinChange(int target, vector<int>& coins)
{
    if (target == 0) {
        return 0; // Base case: 0 coins needed for 0 amount
    }

    int result = INT_MAX;
    for (int i = 0; i < coins.size(); ++i)
    {
        if (coins[i] <= target)
        {
            int subResult = RecursiveMinCoinChange(target - coins[i], coins);
            if (subResult != INT_MAX && subResult + 1 < result)
            {
                result = subResult + 1;
            }
        }
    }

    return result;
}

// Dynamic Programming approach
int MinCoinChange(int target, vector<int>& coins)
{
    vector<int> dp(target + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= target; ++i)
    {
        for (int j = 0; j < coins.size(); ++j)
        {
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX)
            {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    return dp[target];
}

int main()
{
    int target = 20;
    vector<int> coins = {1, 2, 5};

    int minCoinsRecursive = RecursiveMinCoinChange(target, coins);
    int minCoinsDP = MinCoinChange(target, coins);

    cout << "Recursive approach - Minimum number of coins needed: " << minCoinsRecursive << endl;
    cout << "Dynamic Programming - Minimum number of coins needed: " << minCoinsDP << endl;

    return 0;
}
