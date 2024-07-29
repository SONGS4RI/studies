#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n,cnt=0,arr[7]={0},res;
    cin >> n;
    for(int i=666;cnt<n;i++)
    {
        int q=i,w=0;
        res = i;
        for(int j=0;q>0;j++)
        {
            arr[j] = q%10;
            q/=10;
            w++;
        }
        for(int j=0;j<w-2;j++)
        {
            if(arr[j]== 6 && arr[j+1] == 6 && arr[j+2]== 6) 
            {
                cnt++;
                break;
            }
        }
    }
    cout << res;
    return 0;
}