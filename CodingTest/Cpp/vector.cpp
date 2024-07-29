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
    // v.insert(��������ġ�� �ּҰ�,������)
    // v.emplace(������ ��ġ�� �ּ� ��, ���� ��)
    // v.erase(������ ��ġ) or v.erase(������ġ, ����ġ)
    // v.clear()
    return 0;
}
