#include<iostream>
#include<vector>
using namespace std;
int n, res_max=-1000000000, res_min=1000000000, res;
void func(int num[],vector<pair<int,bool>> v_op,int cnt,int res)
{
    if(cnt==n-1)
    {
        if(res>res_max) res_max =res;
        if(res<res_min) res_min =res;
        return;
    }
    for(int i=0;i<n-1;i++)
    {
        if(!v_op[i].second)
        {
            int temp = res;
            v_op[i].second = true;
            if(v_op[i].first==0) res += num[cnt+1];
            else if(v_op[i].first==1) res -= num[cnt+1];
            else if(v_op[i].first==2) res *= num[cnt+1];
            else if(v_op[i].first==3) res /= num[cnt+1];
            func(num,v_op,cnt+1,res);
            res = temp;
            v_op[i].second = false;
        }
    }
}
int main()
{
    cin >> n;
    int num[n],arr[4];
    vector<pair<int,bool>> v_op;
    for(int i=0;i<n;i++) cin >> num[i];
    for(int i=0;i<4;i++) cin >> arr[i];
    for(int i=0;i<4;i++) 
    {
        while(arr[i]--) v_op.push_back(pair<int,bool>(i,false));
    }
    res = num[0];
    func(num,v_op,0,res);
    cout << res_max << "\n" << res_min;
    return 0;
}