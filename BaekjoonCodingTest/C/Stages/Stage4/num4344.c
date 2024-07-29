#include <stdio.h>

int main()
{
    int c;
    scanf("%d", &c);
    for (int i = 0; i < c; i++)
    {
        int n, cnt = 0, sum = 0, mean = 0;
        int score[1000] = {0,};
        float percent = 0;
       
        scanf("%d", &n);

        for (int j = 0; j < n; j++)
        {
            scanf("%d", &score[j]);
            sum += score[j];
        }
        mean = sum / n;
        for (int k = 0; k < n; k++)
        {
            if (score[k] > mean)
            {
                cnt++;
            }
        }
        percent = ((float)cnt / n)*100;
        printf("%.3f%%\n", percent);

    }

    return 0;
}
