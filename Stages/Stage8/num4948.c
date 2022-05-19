#include <stdio.h>
int main()
{
    int n,arr[246913] = {0,};
    arr[0] = 1, arr[1] = 1;
   
    for(int i = 2; i <= n; i++){
        for(int j = 2; i * j <= 2*n; j++){
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
        printf("%d",cnt);
        scanf("%d", &n);
    }
    return 0;
}