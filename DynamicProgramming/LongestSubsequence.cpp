#include<iostream>
#include<string>

using namespace std;

// Recursive approach for LCS
int RecursiveLCS(string text1, string text2, int m, int n)
{
    if (m == 0 || n == 0)
        return 0;

    if (text1[m - 1] == text2[n - 1])
        return 1 + RecursiveLCS(text1, text2, m - 1, n - 1);
    else
        return max(RecursiveLCS(text1, text2, m, n - 1), RecursiveLCS(text1, text2, m - 1, n));
}

// Dynamic Programming approach for LCS
int DP_LCS(string text1, string text2)
{
    int m = text1.length();
    int n = text2.length();

    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (text1[i - 1] == text2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[m][n];
}

int main()
{
    string text1 = "abcde";
    string text2 = "ace";

    int m = text1.length();
    int n = text2.length();

    int recursiveResult = RecursiveLCS(text1, text2, m, n);
    int dynamicResult = DP_LCS(text1, text2);

    cout << "Length of Longest Common Subsequence (Recursive): " << recursiveResult << endl;
    cout << "Length of Longest Common Subsequence (Dynamic Programming): " << dynamicResult << endl;

    return 0;
}
