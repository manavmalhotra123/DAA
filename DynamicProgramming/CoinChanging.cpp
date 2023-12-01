#include<iostream>
#include<vector>
#include<climits>

using namespace std;

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

    cout << "Dynamic Programming - Minimum number of coins needed: " << minCoinsDP << endl;

    return 0;
}
