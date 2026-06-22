/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
string
###End banned keyword*/

#include <iostream>
#include <cmath>
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

//###INSERT CODE HERE -
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

STUDENT maxAverageScore(STUDENT a[], int n)
{
    float max = -1;
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i].aver > max)
        {
            max = a[i].aver;
            index = i;
        }
    }
    return a[index];
}

int main()
{
    STUDENT a[100];
    int n,i;
    char name[35];

    inputArrayStudents(a,n);


    cout<<"\nThe student with the highest average score:\n ";
    cout<<"ID\t|Fullname\t|Date of birth\t|Maths\t|Phys\t|Chemis\t|Average score\n";
    outputStudent(maxAverageScore(a,n));


    return 0;
}
