#include<iostream>
#include<vector>
using namespace std;
int n, res_max=-1000000000, res_min=1000000000, res;
void func(vector<pair<int,bool>> v,int res,int plus,int minus,int multiple,int devide)
{
    if(plus==0 && minus==0 && multiple==0 && devide==0)
    {
        if(res>res_max) res_max =res;
        if(res<res_min) res_min =res;
    }
    for(int i=0;i<n;i++)
    {
        if(!v[i].second)
        {
            v[i].second = true;
            if(multiple!=0)
            {
                res*=v[i].first;
                func(v,res,plus,minus,multiple-1,devide);
            }
            else if(devide!=0)
            {
                res/=v[i].first;
                func(v,res,plus,minus,multiple,devide-1);
            }
            else if(plus!=0) 
            {
                res+=v[i].first;
                func(v,res,plus-1,minus,multiple,devide);
            }
            else if(minus!=0)
            {
                res-=v[i].first;
                func(v,res,plus,minus-1,multiple,devide);
            }
            v[i].second = false;
        }
    }
}
int main()
{
    cin >> n;
    vector<pair<int,bool>> v;
    int num,arr[4];
    for(int i=0;i<n;i++)
    { 
        cin >> num;
        v.push_back(pair<int,bool>(num,false));
    }
    for(int i=0;i<4;i++) cin >> arr[i];
    
    for(int i=0;i<n;i++)
    {
        res = v[i].first;
        v[i].second = true;
        func(v,res,arr[0],arr[1],arr[2],arr[3]);
        v[i].second = false ;
    }
    cout << res_max << "\n" << res_min;
    return 0;
}