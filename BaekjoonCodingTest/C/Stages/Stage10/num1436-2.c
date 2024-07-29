#include <stdio.h>
#include <math.h>
int main()
{
    int res = 665;
    int num;
    scanf("%d", &num);
    int a = 0;
    while (1)
    {
        if (a == num)
        {
            printf("%d", res);
            break;
        }
        res++;
        for (int i = 0; i <= 10; i++)
        {
            if (res / (int)pow(10, i) % 1000 == 666)
            {
                a++; 
                break;
            }
        }
    }
}
