#include <iostream>
using namespace std;

// Fibonacci Recursion 
int FibonacciRecursion(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return FibonacciRecursion(n - 1) + FibonacciRecursion(n - 2);
    }
}

// Fibonacci Memoization 
int fibMemo(int n, int dp[])
{
    if(n == 0 || n == 1)
    {
        return n;
    }

    if(dp[n]!= -1)
    {
        return dp[n];
    }

    dp[n] = fibMemo(n - 1, dp) + fibMemo(n -2, dp);
    return dp[n];
}

int Memo(int n)
{
    int dp[n+1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = -1;
    }
    dp[0] = 0;
    dp[1] = 1;
    int answer = fibMemo(n, dp);
    return answer;
}

// Bottom Up Dynamic Programming
int MemoBottomUp(int n)
{
    int dp[n+1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = -1;
    }
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

// BottomUp Optimization 
int MemoBottomUpOptimization(int n)
{
    if(n == 0 || n == 1)
    {
        return n;
    }
    
    int previous = 0;
    int current = 1;
    int next;

    for(int i = 2; i <= n; i++)
    {
        next = previous + current;
        previous = current;
        current = next;
    }
    
    return current;
}

int main()
{
    int n = 5;
    int recursive = FibonacciRecursion(5);
    cout << "Recursive: " << recursive << endl;

    int answer = Memo(n);
    cout << "Memo: " << answer << endl;

    int bottomUp = MemoBottomUp(n);
    cout << "BottomUp: " << bottomUp << endl;

    int bottomUpOpt = MemoBottomUpOptimization(n);
    cout << "BottomUpOpt: " << bottomUpOpt << endl;

    return 0;
}
