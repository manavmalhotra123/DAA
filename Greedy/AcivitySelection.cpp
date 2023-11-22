#include<iostream>

using namespace std;

class Activity
{
public:
    int Number;
    int StartTime;
    int EndTime;

    void SetValues(int Number, int StartTime, int EndTime)
    {
        this->Number = Number;
        this->StartTime = StartTime;
        this->EndTime = EndTime;
    }
};

void ActivitySelection(Activity ActivityList[], int n)
{
    // Sort activities based on their end times using bubble sort
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (ActivityList[j].EndTime > ActivityList[j + 1].EndTime) {
                // Swap activities
                Activity temp = ActivityList[j];
                ActivityList[j] = ActivityList[j + 1];
                ActivityList[j + 1] = temp;
            }
        }
    }

    // Select activities
    cout << "Selected Activities: ";
    // The first activity will always be selected
    cout << ActivityList[0].Number << " ";
    
    int prevEndTime = ActivityList[0].EndTime;

    for (int i = 1; i < n; ++i) {
        if (ActivityList[i].StartTime >= prevEndTime) {
            // If the start time of the current activity is greater than or equal to
            // the end time of the previous activity, select this activity
            cout << ActivityList[i].Number << " ";
            prevEndTime = ActivityList[i].EndTime;
        }
    }
}

int main()
{
    Activity ActivityList[11];

    ActivityList[0].SetValues(1, 1, 4);
    ActivityList[1].SetValues(2, 3, 5);
    ActivityList[2].SetValues(3, 0, 6);
    ActivityList[3].SetValues(4, 5, 7);
    ActivityList[4].SetValues(5, 3, 9);
    ActivityList[5].SetValues(6, 5, 9);
    ActivityList[6].SetValues(7, 6, 10);
    ActivityList[7].SetValues(8, 8, 11);
    ActivityList[8].SetValues(9, 8, 12);
    ActivityList[9].SetValues(10, 2, 14);
    ActivityList[10].SetValues(11, 12, 16);

    int n = 11; // Number of activities

    ActivitySelection(ActivityList, n);

    return 0;
}
