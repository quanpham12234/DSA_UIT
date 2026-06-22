#include <iostream>
using namespace std;
int main()
{
    int a[5];
    cout << "a  : " << a << endl;
    for (int i = 0; i < 5; i++)
        cout << "&a[" << i << "]: " << &a[i] << endl;
    cout << endl;
    int *b, nb;
    cout << "&nb: " << &nb << endl;
    cout << "b : " << b << endl;
    cout << "&b : " << &b << endl;
    nb = 5;
    b = new int[nb];
    cout << "\nSau cap phat => b: " << b << endl;
    for (int i = 0; i < nb; i++)
        cout << "&b[" << i << "]: " << &b[i] << endl;
    return 0;
}
