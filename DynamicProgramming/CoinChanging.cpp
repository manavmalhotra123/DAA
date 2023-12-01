#include<iostream>
#include<climits>

using namespace std;

int MinCoinChange(int target, int coins[], int numOfCoins)
{
    int dp[target + 1];
    dp[0] = 0;

    for (int i = 1; i <= target; ++i)
    {
        dp[i] = INT_MAX;
        for (int j = 0; j < numOfCoins; ++j)
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
    int coins[] = {1, 2, 5};
    int numOfCoins = sizeof(coins) / sizeof(coins[0]);

    int minCoinsDP = MinCoinChange(target, coins, numOfCoins);

    cout << "Dynamic Programming - Minimum number of coins needed: " << minCoinsDP << endl;

    return 0;
}
