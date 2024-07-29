#include<stdio.h>
int main()
{
    int m,n;
    scanf("%d %d",&m,&n);
    for(int i = m; i <= n; i++)
    {
        for(int j=2; j<=i; j++)
        {
            if((i/j)*j==i && j!=i)
            {
                break;
            }
            if(j==i) printf("%d\n",i);
        }
    }
    return 0;
}
// 시간이 오래걸리므로 에라토스테네스의 체와 같은 방법을
// 사용하여 코딩을 하는 편이 시간을 줄이고 효율적이다.