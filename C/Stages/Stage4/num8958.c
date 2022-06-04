#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main()
{
    int n,sum,score;
    char str[80];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        score = 1;
        scanf("%s", &str);
        for (int j = 0; j < strlen(str); j++)
        {
            if (str[j] == 'O')
            {
                sum += score;
                score++;
            }
            if (str[j] == 'X') score = 1;
        }
        printf("%d\n", sum);

    }

    return 0;
}
