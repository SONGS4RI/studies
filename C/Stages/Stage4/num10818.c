#include<stdio.h>
int main()
{
    int n, max = -1000001, min= 1000001, input;
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &input);
        if (input < min)
        {
            min = input;
        }
        if (input > max)
        {
            max = input;
        }
    }
    printf("%d %d", min, max);

    return 0;
}
