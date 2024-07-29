#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
void func(int arr[],int num)
{
    for(int i=2;num>1;i++)
    {
        if(num%i==0)
        {
            num/=i;
            arr[i]++;
            i--;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int q,w,res_max=1,res_min=1;
    int qarr[10001]={0,},warr[10001]={0,};
    vector<pair<int,int>> res;
    cin >> q >> w;
    func(qarr,q);
    func(warr,w);
    for(int i=0;i<10001;i++)
    {
        int max,min;
        max = qarr[i] < warr[i] ? pow(i,qarr[i]) : pow(i,warr[i]);
        min = qarr[i] > warr[i] ? pow(i,qarr[i]) : pow(i,warr[i]);
        if(max!=0) res.push_back(pair<int,int>(max,min));  
    }
    for(int i=0;i<res.size();i++)
    {
        res_max *= res[i].first;
        res_min *= res[i].second;        
    }
    cout << res_max << "\n" << res_min;
    return 0;
}