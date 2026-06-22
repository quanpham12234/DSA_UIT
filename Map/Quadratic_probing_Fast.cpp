#include <iostream>
#include <vector>

using namespace std;

bool prime(int n)
{
    if (n <= 1)
        return false;
    if (n == 2 || n == 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

enum SlotStatus
{
    EMPTY,
    OCCUPIED,
    DELETED
};

struct Node
{
    int val;
    SlotStatus status;

    Node()
    {
        status = EMPTY;
    }
};

class Hash_Table
{
private:
    int m;    // m: size
    int a, b; // a,b: tham số của hàm băm
    vector<Node> table;
    int current_size; // dùng để kiểm tra table_is_full
    int delete_count;

    int hash_function(int k, int i)
    {
        int mod_k = (k % m + m) % m;
        return ((1LL * mod_k) + (1LL * a * i) + (1LL * b * i * i)) % m;
    }

public:
    Hash_Table(int size, int a, int b)
    {
        m = size;
        this->a = a;
        this->b = b;
        table.resize(m);
        current_size = 0;
        delete_count = 0;
    }

    bool table_is_full()
    {
        return current_size == m;
    }

    int getCurrent_Count()
    {
        return current_size;
    }

    void up_size()
    {
        int i = 2 * current_size + 1;

        while (!prime(i))
        {
            i++;
        }

        int old_m = m;
        m = i;
        vector<Node> old_table = table;

        table.clear();
        table.resize(m);
        current_size = 0;
        delete_count = 0;

        for (int i = 0; i < old_m; i++)
        {
            if (old_table[i].status == OCCUPIED)
            {
                insert(old_table[i].val);
            }
        }
    }

    bool isNone(int index)
    {
        return table[index].status == EMPTY;
    }

    int getDeleted_Count()
    {
        return delete_count;
    }

    bool remove(int key)
    {
        int i = 0;
        int index = hash_function(key, i);

        while (i < m && table[index].status != EMPTY)
        {
            if (table[index].val == key && table[index].status == OCCUPIED)
            {
                table[index].status = DELETED;

                current_size--;
                delete_count++;
                return true;
            }
            i++;
            index = hash_function(key, i);
        }

        return false;
    }

    bool insert(int key)
    {
        int i = 0;
        int index = hash_function(key, i);

        while (i < m && table[index].status != EMPTY)
        {
            if (table[index].status == OCCUPIED && table[index].val == key)
            {
                return true;
            }

            i++;
            index = hash_function(key, i);
        }

        if (table[index].status == EMPTY)
        {
            table[index].val = key;
            table[index].status = OCCUPIED;

            current_size++;
            return true;
        }

        return false;
    }

    void Duyet()
    {
        for (int i = 0; i < m; i++)
        {
            if (table[i].status == EMPTY)
            {
                cout << "None";
            }

            else if (table[i].status == DELETED)
            {
                cout << "DELETED";
            }

            else
                cout << table[i].val;

            if (i != m - 1)
                cout << ", ";
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, a, b;
    cin >> m >> a >> b;

    Hash_Table ht(m, a, b);

    int choice;

    while (true)
    {
        cin >> choice;
        if (choice == 0)
            break;

        int num;
        if (choice == 1)
        {
            cin >> num;
            bool success = ht.insert(num);

            if (success == false)
            {
                ht.up_size();
                ht.insert(num);
            }
        }

        else if (choice == 2)
        {
            cin >> num;
            bool isdeleted = ht.remove(num);

            if (!isdeleted)
                if (ht.getDeleted_Count() * 2 >= ht.getCurrent_Count())
                    ht.up_size();
        }
    }

    ht.Duyet();

    return 0;
}