#include <iostream>

using namespace std;

const int MAX = 10000;

struct Queue
{
    int a[MAX];
    int Front; // index phần tử đầu
    int Rear;  // index phần tử cuối
};

void Create_Queue(Queue &q)
{
    q.Front = -1;
    q.Rear = -1;
}

bool isEmpty(const Queue &q)
{
    return (q.Front == -1);
}

bool isFull(const Queue &q)
{
    return (q.Rear - q.Front + 1 == MAX);
}

void EnQueue(Queue &q, int x)
{
    if (isFull(q) == true)
    {
        cout << "Hang doi da day! \n";
        return;
    }

    else
    {
        if (isEmpty(q) == true)
        {
            q.Front = 0;
            q.Rear = -1;
        }

        if (q.Rear == MAX - 1)
        {
            int f = q.Front;
            int r = q.Rear;

            for (int i = f; i <= r; i++)
            {
                q.a[i - f] = q.a[i];
            }

            q.Front = 0;
            q.Rear = r - f;
        }

        q.Rear++;
        q.a[q.Rear] = x;
    }
}

void DeQueue(Queue &q)
{
    if (isEmpty(q) == true)
    {
        cout << "Hang cho rong! \n";
        return;
    }

    q.Front++;
    if (q.Front > q.Rear) // 1 phần tử
    {
        q.Front = -1;
        q.Rear = -1;
    }
}

int Front(Queue &q) {
    return q.Front;
}