#include <iostream>
#include <tuple>
using namespace std;

// pair<datatype1, datatype2> v;
// make_pair(a,b / {a,b};
// v.first : datatype1 ; v.second : datatype2


int main()
{
    tuple<int,int,int> t = make_tuple(1,2,3);
    cout << get<1>(t) << endl;
    return 0;
}