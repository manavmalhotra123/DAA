#include <iostream>
#include <algorithm>

using namespace std;


class Activity
{
public:
    int id;
    int start;
    int end;

    void Set(int id, int start, int end)
    {
        this->id = id;
        this->start = start;
        this->end = end;
    }
};

void SwappedActivity(Activity &one, Activity &two)
{
    Activity temp = one;
    one = two;
    two = temp;
}

void SortActivityWithFinishTime(Activity arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j].end > arr[j + 1].end)
            {
                SwappedActivity(arr[j], arr[j + 1]);
            }
        }
    }
}

int MaxActivityNumbers(Activity arr[], int n)
{
    int answer = 1;
    SortActivityWithFinishTime(arr, n);

    int lastSelected = 0;

    for (int i = 1; i < n; i++)
    {
        if (arr[i].start >= arr[lastSelected].end)
        {
            answer++;
            lastSelected = i;
        }
    }

    return answer;
}

int main()
{
    Activity arr[] = {{1, 5, 9}, {2, 1, 2}, {3, 3, 4}, {4, 0, 6}, {5, 5, 7}, {6, 8, 9}};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Maximum number of activities that can be accommodated: " << MaxActivityNumbers(arr, n) << std::endl;

    return 0;
}
