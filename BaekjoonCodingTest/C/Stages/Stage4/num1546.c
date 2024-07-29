#include <stdio.h>

int main() {

    int n;
    float input,max=-1,sum=0, mean=0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%f", &input);
        if (input > max) { max = input; }
        sum += input;

    }
    mean = (sum  * 100 / max ) / n;
    printf("%f", mean);
    return 0;
}
