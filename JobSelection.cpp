#include <iostream>

using namespace std;

class Job
{
public:
    int id;
    int profit;
    int deadline;

    void SetValues(int id, int profit, int deadline)
    {
        this->id = id;
        this->profit = profit;
        this->deadline = deadline;
    }
};

void SwapJob(Job &one, Job &two)
{
    Job temp = one;
    one = two;
    two = temp;
}

void ProfitSort(Job arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i].profit < arr[j].profit)
            {
                SwapJob(arr[i], arr[j]);
            }
        }
    }
}

int MaxProfit(Job arr[], int n)
{
    // Sorting of the Jobs based on profit
    ProfitSort(arr, n);

    bool included[n];
    for (int i = 0; i < n; i++)
    {
        included[i] = false;
    }

    int Profit = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = min(n, arr[i].deadline) - 1; j >= 0; j--)
        {
            if (!included[j])
            {
                included[j] = true;
                Profit += arr[i].profit;
                break;
            }
        }
    }
    return Profit;
}

int main(int argc, char const *argv[])
{
    
    Job jobs[4];

    jobs[0].SetValues(1, 100, 2);
    jobs[1].SetValues(2, 10, 1);
    jobs[2].SetValues(3, 15, 2);
    jobs[3].SetValues(4, 27, 1);

    int n = sizeof(jobs) / sizeof(jobs[0]);

    cout << "Max Profit: " << MaxProfit(jobs, n) << endl;

    return 0;
}
