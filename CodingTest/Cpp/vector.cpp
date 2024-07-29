#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    vector<int> v = { 1, 2, 3, 4};

    for_each(v.begin(), v.end(), [&](int& n)
    {
        cout << n << endl;        //output : 1 2 3 4
    });

    for_each(v.rbegin(), v.rend(), [&](int& n) 
    {
        cout << n << endl;        //output : 4 3 2 1
    });
    ///////////////////////////////////////////////////
    vector<int>::iterator itor = v.begin();

    for (; itor != v.end(); itor++)
        cout << *itor << endl;        //output : 1 2 3 4


    vector<int>::reverse_iterator itor2 = v.rbegin();

    for (; itor2 != v.rend(); itor2++)
        cout << *itor2 << endl;        //output : 4 3 2 1
    //////////////////////////////////////////////////
    cout << v.front() << endl;        //output : 1
    cout << v.back() << endl;        //output : 4
    cout << v.at(1) << endl;        //output : 2
    cout << v[2] << endl;            //output : 3?
    v.push_back(5);
    v.pop_back();
    // v.insert(삽일할위치의 주소값,변수값)
    // v.emplace(삽입할 위치의 주소 값, 변수 값)
    // v.erase(삭제할 위치) or v.erase(시작위치, 끝위치)
    // v.clear()
    return 0;
}
