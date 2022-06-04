#include<stdio.h>
void star(int i, int j, int N);

int main(void)
{
    int N, i, j;
    scanf("%d",&N);

    for (i=0;i<N;i++)
    {
        for (j=0;j<N;j++)
        {
            star(i, j, N);
        }
        printf("\n");
    }
    return 0;

}
void star(int i, int j, int N)
{
    if((i/N)%3==1 && (j/N)%3==1) printf(" ");
    else
    {
        if (N/3==0) printf("*");
        else star(i,j,N/3);
    }
}
