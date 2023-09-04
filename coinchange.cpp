#include<iostream>

int Solver(int coins[], int number_of_coins, int TargetAmount)
{
    
}



int main(int argc, char const *argv[])
{
    int coins[] = {1,2,5};
    int number_of_coins = sizeof(coins)/sizeof(coins[0]);
    int target_amount = 5;

    int answer = Solver(coins, number_of_coins, target_amount);
    return 0;
}
