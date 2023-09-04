#include <iostream>

using namespace std;

class Stack
{
    int size;
    int top;
    int *arr;

public:
    Stack(int size)
    {
        this->size = size;
        this->top = -1;
        this->arr = new int[size];
    }

    void push(int data)
    {
        if (top < size - 1)
        {
            top++;
            arr[top] = data;
        }
    }
    int pop()
    {
        if (top >= 0)
        {
            int data = arr[top];
            top--;
            return data;
        }
        return -1;
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

class Queue
{
private:
    int front, rear, capacity;
    int *array;

public:
    Queue(int size)
    {
        capacity = size;
        front = rear = -1;
        array = new int[capacity];
    }

    void Enqueue(int item)
    {
        if (rear == capacity - 1)
        {
            return;
        }
        array[++rear] = item;
    }

    int Dequeue()
    {
        if (front == rear)
        {
            return -1;
        }
        return array[++front];
    }

    bool IsEmpty()
    {
        return front == rear;
    }
};

class Graph
{
private:
    int nodes;
    int **Adj;

public:
    Graph(int nodes)
    {
        this->nodes = nodes;
        Adj = new int *[nodes];
        for (int i = 0; i < nodes; i++)
        {
            Adj[i] = new int[nodes];
            for (int j = 0; j < nodes; j++)
            {
                Adj[i][j] = 0;
            }
        }
    }

    void AddEdge(int sv, int ev, bool directed)
    {
        Adj[sv][ev] = 1;
        if (!directed)
        {
            Adj[sv][ev] = 1;
        }
    }

    void show()
    {
        for (int i = 0; i < nodes; i++)
        {
            for (int j = 0; j < nodes; j++)
            {
                cout << Adj[i][j] << " ";
            }
            cout << endl;
        }
    }

    void BFS(int source)
    {
        bool *visited = new bool[nodes];
        for (int i = 0; i < nodes; i++)
        {
            visited[i] = false;
        }

        Queue queue(nodes);
        queue.Enqueue(source);
        visited[source] = true;

        cout << "BFS traversal starting from node " << source << ": ";
        while (!queue.IsEmpty())
        {
            int currentNode = queue.Dequeue();
            cout << currentNode << " ";

            for (int i = 0; i < nodes; i++)
            {
                if (Adj[currentNode][i] == 1 && !visited[i])
                {
                    queue.Enqueue(i);
                    visited[i] = true;
                }
            }
        }
        cout << endl;

        delete[] visited;
    }

    void DFS(int source)
    {
        bool *visited = new bool[nodes];
        for (int i = 0; i < nodes; i++)
        {
            visited[i] = false;
        }

        Stack stack(nodes);
        stack.push(source);
        visited[source] = true;

        cout << "DFS traversal starting from node " << source << ": ";
        while (!stack.isEmpty())
        {
            int currentNode = stack.pop();
            cout << currentNode << " ";

            for (int i = 0; i < nodes; i++)
            {
                if (Adj[currentNode][i] == 1 &&!visited[i])
                {
                    stack.push(i);
                    visited[i] = true;
                }
            }
        }
    }
};

int main()
{
    int nodes = 5;
    Graph g(nodes);

    g.AddEdge(0, 1, true);
    g.AddEdge(0, 2, true);
    g.AddEdge(1, 2, true);
    g.AddEdge(1, 3, true);
    g.AddEdge(2, 4, true);
    g.AddEdge(3, 4, true);

    g.show();

    int startNode = 0; 
    g.BFS(startNode);

    g.DFS(startNode);
    return 0;
}

/*
1. DFS implementation krna hai
2. text file waala graph ka
*/