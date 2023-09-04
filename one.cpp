#include<iostream>

using namespace std;


class Queue
{
private:
    int front;
    int rear;
    int capacity;
    int *arr;
public:
    Queue(int capacity) {
        cout << "Queue of size " << capacity << " is created " << endl;
        this->capacity = capacity;
        this->arr = new int[capacity];
        this->front = -1;
        this->rear = -1;
    }

    void enqueue(int data) {
        if (rear < capacity - 1) {
            rear++;
            arr[rear] = data;
        }
    }

    int dequeue() {
        if (front < rear) {
            front++;
            return arr[front];
        }
        return -1; // Return a sentinel value to indicate an empty queue
    }

    bool isEmpty() {
        if (front == rear) {
            return true;
        }
        else {
            return false;
        }
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
        Adj = new int*[nodes];
        for(int i = 0; i < nodes; i++){
            Adj[i] = new int[nodes];
            for(int j = 0; j < nodes; j++){
                Adj[i][j] = 0;
            }
        }
    }


    void WeightlessAddEdge(int u, int v, bool directed)
    {
        Adj[u][v] = 1;
        if(!directed)
        {
            Adj[v][u] = 1;
        }
    }

    void WeightAddEdge(int u, int v, int weight, bool directed)
    {
        Adj[u][v] = weight;
        if(!directed)
        {
            Adj[v][u] = weight;
        }
    }


    void BFS(int start)
    {
        int *visited = new int[nodes];
        for(int i = 0; i < nodes; i++)
        {
            visited[i] = 0;
        }
        Queue q(nodes);
        q.enqueue(start);
        visited[start] = 1;
        while(!q.isEmpty())
        {
            int u = q.dequeue();
            cout<<u<<" ";
            for(int i = 0; i < nodes; i++)
            {
                if(visited[i] == 0 && Adj[u][i]!= 0)
                {
                    q.enqueue(i);
                    visited[i] = 1;
                }
            }
        }
        cout<<endl;
    }

    void show()
    {
        for(int i = 0; i < nodes; i++){
            for(int j = 0; j < nodes; j++){
                cout << Adj[i][j] << " ";
            }
            cout << endl;
        }
    }
};


int main()
{
    Graph g(4);
    g.WeightlessAddEdge(0, 1,true);
    g.WeightlessAddEdge(0, 2,true);
    g.WeightlessAddEdge(1, 2,true);
    g.WeightlessAddEdge(2, 0,true);

    cout<<"Adjacency Matrix of the graph"<<endl;
    g.show();
 

    cout<<"BFS with the source "<<0<<" is "<<endl;
    g.BFS(0);

    return 0;
}