#include<iostream>
using namespace std;
struct compare
{
    int kg;
    int m;
};
int main()
{
    int n;
    cin >> n;
    compare arr[n]={0,};
    for(int i=0;i<n;i++) cin >> arr[i].kg >> arr[i].m;
    for(int i=0;i<n;i++)
    {
        int cnt =1;
        for(int j=0;j<n;j++)
        {
            if(i!=j && arr[i].kg < arr[j].kg && arr[i].m < arr[j].m) cnt++;
        }
        cout << cnt << " ";
    }
    return 0;
}