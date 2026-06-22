#include <iostream>

using namespace std;

const int MAX = 10000;

struct Stack
{
    int a[MAX];
    int n;
};

void Create_Stack(Stack &s)
{
    s.n = -1;
}

bool is_Empty(const Stack &s)
{
    if (s.n == -1)
        return true;

    return false;
}

bool is_Full(const Stack &s)
{
    if (s.n >= MAX - 1)
        return true;
    return false;
}

void push(Stack &s, int x) {
    if (is_Full(s) == true)
        return;

    s.a[++s.n] = x;
}

void pop(Stack& s) {
    if (is_Empty(s) == true)
        return;
    
    s.n--;
}

int top(Stack& s) {
    if (is_Empty(s) == true)
        return -1;

    return s.a[s.n];
}

int main()
{
    Stack st;
    Create_Stack(st);
    push(st,5);
    push(st,4);
    push(st,-3);
    push(st,7);
    push(st,5);
    push(st,2);
    push(st,1);

    cout << top(st) << "\n";

    pop(st);

    cout << top(st) << "\n";

    return 0;
    
}