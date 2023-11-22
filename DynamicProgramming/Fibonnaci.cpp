#include<iostream>

using namespace std;

int RecursionFibonacci(int n)
{
    if(n <= 1)
    {
        return n;
    }
    else
    {
        return RecursionFibonacci(n - 1) + RecursionFibonacci(n - 2);
    }
}

int FibonacciDynamically(int n)
{
    int dp[n+1];
    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i <= n; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}


int main()
{
    int n = 5; // Finding the 5th Fibonacci number
    int answer = RecursionFibonacci(n);
    cout << "The " << n << "th Fibonacci number is: " << answer << endl;
    return 0;
}
