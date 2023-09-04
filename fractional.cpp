#include<iostream>

using namespace std;

class Item
{
public:
    int weight;
    int profit;
    double ratio()
    {
        return (double)profit/weight;
    }
};

void swap(Item& a,Item& b)
{
    Item temp = a;
    a = b;
    b = temp;
}

// Applying quick sort 
int partition(Item arr[],int low, int high)
{
    double pivot = arr[high].ratio();
    int i = (low-1);
    for(int j=low;j<high;j++)
    {
        if(arr[j].ratio() > pivot)  // Changed to descending order
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return (i+1);
}

void quickSort(Item arr[],int low,int high)
{
    if(low<high)
    {
        int pivot = partition(arr,low,high);
        quickSort(arr,low,pivot-1);
        quickSort(arr,pivot+1,high);
    }
}

// fractional knapsack 
double knapsack(int Capacity, Item arr[], int n)
{
    quickSort(arr,0,n-1);

    int currentweight = 0;
    double answer = 0;

    for(int i=0;i<n;i++)
    {
        if(currentweight + arr[i].weight <= Capacity)
        {
            answer += arr[i].profit;
            currentweight += arr[i].weight;
        }
        else
        {
            int remain = Capacity - currentweight;
            answer += arr[i].profit * ((double)remain / arr[i].weight);
            break;
        }
    }
    return answer;
}

int main()
{
    Item arr[] = {{1, 5}, {3, 10}, {5, 15},{4,7},{1,8},{3,9},{2,4}};
    int n = sizeof(arr)/sizeof(arr[0]);
    int Capacity = 15;
    cout << "Profit = " << knapsack(Capacity, arr, n) << std::endl;
    return 0;
}
