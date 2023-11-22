#include<iostream>
#include<algorithm>

using namespace std;

class Job
{
public:
    int id;
    int profit;
    int Deadline;

    void SetValues(int id, int profit, int Deadline)
    {
        this->id = id;
        this->profit = profit;
        this->Deadline = Deadline;
    }
};

bool Compare(Job job1, Job job2)
{
    return job1.profit > job2.profit; // Sort jobs in descending order of profit
}

void JobSequencing(Job jobs[], int n)
{
    sort(jobs, jobs + n, Compare); // Sort jobs based on profit

    int maxDeadline = 0;
    for (int i = 0; i < n; ++i)
    {
        if (jobs[i].Deadline > maxDeadline)
        {
            maxDeadline = jobs[i].Deadline;
        }
    }

    int* result = new int[maxDeadline + 1]; // Array to store job sequence
    for (int i = 0; i <= maxDeadline; ++i)
    {
        result[i] = -1; // Initialize all slots as empty
    }

    int maxProfit = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = jobs[i].Deadline; j > 0; --j)
        {
            if (result[j] == -1) // Slot is available
            {
                result[j] = jobs[i].id;
                maxProfit += jobs[i].profit;
                break;
            }
        }
    }

    // Print job sequence and maximum profit
    cout << "Job Sequence: ";
    for (int i = 1; i <= maxDeadline; ++i)
    {
        if (result[i] != -1)
        {
            cout << result[i] << " ";
        }
    }
    cout << "\nMaximum Profit: " << maxProfit << endl;

    delete[] result; // Free allocated memory
}

int main()
{
    Job jobs[4];
    jobs[0].SetValues(1, 100, 2);
    jobs[1].SetValues(2, 10, 1);
    jobs[2].SetValues(3, 15, 1);
    jobs[3].SetValues(4, 27, 1);

    int n = 4;

    JobSequencing(jobs, n);

    return 0;
}
