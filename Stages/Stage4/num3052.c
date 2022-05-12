#include <stdio.h>

int main() {
    int a[10], result=0;
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);
        a[i] = a[i] % 42;
    }
    
    for (int i = 0; i < 10; i++)
    {
        int cnt = 0;
        for (int j = i + 1; j < 10; j++)
        {
            if (a[i] == a[j]) cnt++;
        }
        if (cnt == 0)
        {
            result++;
        }
    }
    
    printf("%d", result);
    return 0;
}
