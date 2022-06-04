#include <stdio.h>
int main()
{
    int n,arr[246913] = {0,};
    arr[0] = 1, arr[1] = 1;
    scanf("%d", &n);
    for(int i = 2; i <= 246913; i++){
        for(int j = 2; i * j <= 246913; j++){
            arr[i*j] = 1;
        }
    }
    while(n!=0)
    {
        int cnt=0;
        for(int i = n+1; i <= 2*n; i++){
            if(arr[i] == 0)
                cnt++;
        }
        printf("%d\n",cnt);
        scanf("%d", &n);
    }
    return 0;
}