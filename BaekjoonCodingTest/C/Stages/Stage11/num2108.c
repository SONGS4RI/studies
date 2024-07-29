#include<stdio.h>
#include <math.h>
int compare(const void *a, const void *b)
{
    int num1 = *(int *)a;
    int num2 = *(int *)b;
 
    if (num1 < num2)
        return -1;
    if (num1 > num2)
        return 1;
    return 0;
}
int main()
{
    int n, arr[8001]={0,}, res[500000]={0,},num,sum=0, cnt=0;
    int max =0, max1=0,max2=0,flag;
    double mean;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&num);
        sum += num;
        arr[num+4000]++;
    }
    for(int i=8000; i>=0; i--)
    {
        for(int j=0; j<arr[i];j++)
        {
            res[cnt] = i-4000;
            cnt++;
        }
        if(arr[i]>max)
        {
            max = arr[i];
            max1 = i-4000;
            max2 = 0;
            flag = 0;
        }
        if(arr[i]==max && arr[i]!=0)
        {
            max2 = max1;
            max1 = i-4000;
            flag = 1;
        }
    }
    qsort(res, n, sizeof(int), compare);
    // »ê¼úÆò±Õ
    mean = (double)sum/n;
    printf("%d\n",(int)round(mean));
    // Áß¾Ó°ª
    printf("%d\n",res[n/2]);
    // ÃÖºó°ª
    if(flag == 0) printf("%d\n",max1);
    else if(flag ==1) printf("%d\n",max2);
    // ¹üÀ§
    printf("%d\n",res[n-1]-res[0]);

    return 0;
}