#include<iostream>
using namespace std;
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,arr[10002]={0,},num;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> num;
        arr[num]++;
    } 
    for(int i=0;i<10002;i++)
    {
        if(arr[i]!=0)
        {
            for(int j=0;j<arr[i];j++) cout << i << "\n";
        }
    }
    return 0;
}