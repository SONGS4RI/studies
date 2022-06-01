int compare(const void *a,const void *b)
{
    int A = *(int*) a;
    int B = *(int*) b;
    if(A>B) return 1;
    else if(A<B) return -1;
    return 0;
}
int main()
{   
    int n;
    scanf("%d",&n);
    int arr[n];
    qsort(arr,n,sizeof(int),compare);
}