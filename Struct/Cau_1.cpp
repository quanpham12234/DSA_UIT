/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
include
###End banned keyword*/

#include <iostream>
#include <string>
using namespace std;

//###INSERT CODE HERE -
struct PhanSo {
    int tu;
    int mau;
};

struct PS {
    int b;
};

struct DIEM {
    double x;
    double y;
};

struct VECTOR {
    double x;
    double y;
    double z;
};

struct DATE
{
    int ngaysinh;
    string thang;
    int nam;  
};

struct nhancong {
    string ten;
    string que_quan;
    double bacluong;
    DATE ngaysinh;
}; 



int main()
{
    string test;cin>>test;

    PhanSo a={1,2}; PS b;
    cout<<a.tu<<"/"<<a.mau<<endl;

    DIEM M = {0.5,0.7};
    cout<<"("<<M.x<<","<<M.y<<")"<<endl;

    VECTOR P = {1.2,0.3,1};
    cout<<"P("<<P.x<<","<<P.y<<","<<P.z<<")"<<endl;

    nhancong nguoi_a ={"Hoang Nam","TP HCM",3.4,10,"Mot",1999} , nguoi_b ={"Thuy Van","Dong Nai",4,21,"Muoi Hai",1990}; // Tao 2 nhancong la nguoi_a, nguoi_b
    cout << nguoi_a.ten;        // Xuat ten cua nguoi_a
    float S = nguoi_a.bacluong + nguoi_b.bacluong;//    Cong bacluong cua nguoi_a, nguoi_b
    cout<<nguoi_b.ngaysinh.nam; //Xuat ngaysinh cua nguoi_b

    return 0;
}