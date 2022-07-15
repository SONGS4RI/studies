#include<iostream>
#include<vector>
using namespace std;
vector<pair<int,bool>> v;
int max=-100000001,n;
int func()
{
    for(int i=0;i<n;i++)
    {
        if(v[i].second)
        {
            int sum=0;
            
        }
    }
}
int main()
{
    int num;
    cin >> n;
    for(int i=0;i<n;i++) 
    {
        cin >> num;
        if(num>=0) v.push_back(pair<int,bool>(num,true));
        else v.push_back(pair<int,bool>(num,false));
    }

    return 0;
}