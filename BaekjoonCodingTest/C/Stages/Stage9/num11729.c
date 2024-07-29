#include <stdio.h>

void hanoi(int n, int start, int middle, int end) 
{
    if (n == 1)
    {
        printf("%d %d\n", start, end);
        return;
    }
    hanoi(n - 1, start, end, middle);
    hanoi(1, start, middle, end);
    hanoi(n - 1, middle, start, end);
}

int main()
{
    int N,pow=1;
    scanf("%d", &N);
    for(int i=0;i<N;i++) pow = pow*2;
    int cnt = pow - 1;
    printf("%d\n", cnt);
    hanoi(N, 1, 2, 3);

    return 0;
 }