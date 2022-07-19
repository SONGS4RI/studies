#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int n,cnt=1,num;
    cin >> n;
    vector<int> arr;
    for(int i=0;i<n;i++)
    {
        cin >> num;
        arr.push_back(num);
    }
    vector<int> arr_list(arr);
    sort(arr_list.begin(),arr_list.end());
    arr_list.erase(unique(arr_list.begin(),arr_list.end()),arr_list.end());
    auto first = find(arr.begin(),arr.end(),arr_list[0]);
    int a = first-arr.begin();
    for(int i=1;i<arr_list.size();i++)
    {
        auto temp = find(arr.begin(),arr.end(),arr_list[i]);
        int b= temp-arr.begin();
        if(a > b)
        {
            arr.erase(temp);
            i--;
        }
        else
        {
            first = temp;
            a = first-arr.begin();
        }
    }
    cout << cnt;
    return 0;
}