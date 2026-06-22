#include <iostream>
#include <queue>
#include <random>
#include <ctime>

using namespace std;

// priority_queue
// push
// size
// empty
// pop : Xoa phan tu o dau
// top : Lay ra phan tu o dau, mac dinh la lon nhat

int main()
{
    priority_queue<int> pq;
    int n; cin >> n;

    for (int i = 0;i < n ;i++)
    pq.push(rand() % 100);

    cout << pq.top() << endl;

    int newtop; cin >> newtop;
    pq.push(newtop);
    
    cout << pq.top() << endl;
    pq.pop();

    cout << pq.top() << endl;

    return 0;
}