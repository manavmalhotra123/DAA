#include<iostream>
#include<algorithm> // For sorting

using namespace std;

class Object
{
public:
    int id;
    int Weight;
    int Value;
    double Ratio; // Changed to double for ratio calculation

    void SetValue(int id, int Weight, int Value)
    {
        this->id = id;
        this->Weight = Weight;
        this->Value = Value;
        this->Ratio = static_cast<double>(Value) / static_cast<double>(Weight); // Calculate ratio
    }
};

bool Compare(Object obj1, Object obj2)
{
    return obj1.Ratio > obj2.Ratio; // Sort in descending order of ratio
}

double FractionalKnapSack(Object objects[], int n, int capacity)
{
    sort(objects, objects + n, Compare); // Sort objects based on ratio

    double totalValue = 0.0;
    int currentWeight = 0;

    for (int i = 0; i < n; ++i)
    {
        if (currentWeight + objects[i].Weight <= capacity)
        {
            // Take the whole object if it fits in the knapsack
            currentWeight += objects[i].Weight;
            totalValue += objects[i].Value;
        }
        else
        {
            // Take a fraction of the object to fill the knapsack
            int remainingCapacity = capacity - currentWeight;
            totalValue += objects[i].Ratio * remainingCapacity;
            break; // Knapsack filled, so exit loop
        }
    }

    return totalValue;
}

int main()
{
    Object objects[7];
    objects[0].SetValue(1, 1, 5);
    objects[1].SetValue(2, 3, 10);
    objects[2].SetValue(3, 5, 15);
    objects[3].SetValue(4, 4, 7);
    objects[4].SetValue(5, 1, 8);
    objects[5].SetValue(6, 3, 9);
    objects[6].SetValue(7, 2, 4);

    int n = 7;
    int capacity = 20; // Knapsack capacity

    double maxValue = FractionalKnapSack(objects, n, capacity);
    cout << "Maximum value in the knapsack: " << maxValue << endl;

    return 0;
}
