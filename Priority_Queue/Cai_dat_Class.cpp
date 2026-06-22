#include <iostream>
#include <vector>
using namespace std;

class Priority_Queue
{
private:
    vector<int> heap;

    int parent(int i) {return (i - 1) / 2;}
    int left(int i) { return (2 * i + 1);}
    int right(int i) { return (2 * i + 2);}
    
    void heapify_up(int i)
    {
        while(i > 0 && heap[parent(i)] < heap[i])
        {
            swap(heap[parent(i)],heap[i]);
            i = parent(i);
        }
    }

    void heapify_down(int i)
    {
        int largest = i;
        int l = left(i);
        int r = right(i);
        
        if (l < heap.size() && heap[l] > heap[largest]) largest = l;
        if (r < heap.size() && heap[r] > heap[largest]) largest = r;
        
        if (largest != i)
        {
            swap(heap[largest],heap[i]);
            heapify_down(largest);
        }
    }

    public:
    void push(int val)
    {
        heap.push_back(val);
        heapify_up(heap.size()-1);
    }

    void pop()
    {
        if (heap.empty()){
            cout << "Hang doi hien khong co phan tu nao het!" << endl;
            return;
        }

        heap[0] = heap.back();
        heap.pop_back();

        if (!heap.empty())
        heapify_down(0);
    }

    int top()
    {
        if (heap.empty()){
            cout << "Hang doi hien khong co phan tu nao het!" << endl;
            return -1;
        }
        return heap[0];
    }

    bool empty()
    {
        return heap.empty();
    }

    int size()
    {
        return heap.size();
    }
};

int main()
{
    Priority_Queue pq;
    pq.push(1);
    pq.push(8);
    pq.push(4);
    pq.push(6);

    cout << pq.top() << endl;

    pq.pop();

    cout << pq.top() << endl;

    return 0;
    
}
