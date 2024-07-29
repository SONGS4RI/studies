#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int Bsearch(vector<int> v, int target)
{
    int left = 0;
    int right = (int)v.size()-1;
    while(left<=right)
    {
        int mid = (left+right)/2;
        if(target==v[mid]) return mid;
        else if(target>v[mid]) left = mid + 1;
        else right = mid -1;
    }
    return -1;
}
int main()
{
    vector<int> nums = {1,3,5,7,9,20,40,80};
    int n;
    cin >> n;
    cout << "target index : " <<Bsearch(nums,n);
    return 0;
}