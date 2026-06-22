#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

enum Node_Status
{
    EMPTY,
    OCCUPIED
};

struct Node
{
    Node_Status status;
    int val;

    Node()
    {
        status = EMPTY;
    }
};

class Hash_Table
{
private:
    int capacity;
    int a, b; // Dùng để băm
    int current_count;

    vector<Node> table;

    int Hash_Function(int key, int i)
    {
        int mod_key = (key % capacity + capacity) % capacity;
        return ((mod_key % capacity) + a * i + b * i * i) % capacity;
    }

public:
    Hash_Table(int m, int a, int b)
    {
        capacity = m;
        this->a = a;
        this->b = b;
        current_count = 0;

        table.resize(capacity);
    }

    bool is_full()
    {
        return current_count == capacity;
    }

    void insert(int key)
    {
        int i = 0;

        while (i < capacity)
        {
            int index = Hash_Function(key, i);

            if (table[index].status == EMPTY)
            {
                table[index].status = OCCUPIED;
                table[index].val = key;
                current_count++;

                return;
            }

            if (table[index].val == key)
                return;
            i++;
        }
    }

    void Duyet()
    {
        int size = table.size();

        for (int i = 0; i < size; i++)
        {
            if (table[i].status == EMPTY)
            {
                cout << "None";
            }
            else
            {
                cout << table[i].val;
            }

            if (i != (size - 1))
                cout << ", ";
        }
        cout << "\n";
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true)
    {
        int m;
        cin >> m;

        if (m == 0)
            break;

        int a, b;
        cin >> a >> b;

        Hash_Table ht(m, a, b);

        string line;
        cin.ignore();

        getline(cin, line);

        stringstream ss(line);

        int x;
        while (ss >> x)
        {
            if (!ht.is_full())
                ht.insert(x);
        }

        ht.Duyet();
    }

    return 0;
}