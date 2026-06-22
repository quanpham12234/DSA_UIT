
/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
string
###End banned keyword*/

#include <iostream>
#include <math.h>
#include <cstring>
using namespace std;

struct DATE
{
    int day, month, year;
};
typedef struct STUDENT
{
    char id[11];
    char name[35];
    DATE dob;
    float math, phy, chem, aver;

} SV;

// ###INSERT CODE HERE -
void inputStudent(STUDENT &a)
{
    cin.getline(a.id,11);
    cin.getline(a.name,35);
    cin >> a.dob.day >> a.dob.month >> a.dob.year;
    cin >> a.math >> a.phy >> a.chem;
    a.aver = (a.math + a.phy + a.chem)/3;
}

void inputArrayStudents(STUDENT a[], int &n)
{
    cin >> n;
    for (int i = 0; i<  n; i++)
    {
        cin.ignore();
        inputStudent(a[i]);
    }
}

void outputStudent(STUDENT a)
{
    cout << a.id << "\t|" << a.name << "\t|";
    cout << a.dob.day << "/" << a.dob.month << "/" << a.dob.year << "\t|";
    cout << a.math << "\t|" << a.phy << "\t|" << a.chem << "\t|" << a.aver;  
}

void outputArrayStudents(STUDENT a[],int n)
{
    for (int i = 0; i < n; i++)
    {
        outputStudent(a[i]);
        cout << endl;
    }
}

int main()
{
    STUDENT a[100];
    int n;

    inputArrayStudents(a, n);
    cout << "ID\t|Full name\t|Date of birth\t|Maths\t|Phys\t|Chemis\t|Average score\n";
    outputArrayStudents(a, n);

    return 0;
}
