#include<stdio.h>
int main()
{
    int m,n;
    scanf("%d %d",&m,&n);
    for(int i = m; i <= n; i++)
    {
        for(int j=2; j<=i; j++)
        {
            if((i/j)*j==i && j!=i)
            {
                break;
            }
            if(j==i) printf("%d\n",i);
        }
    }
    return 0;
}
// �ð��� �����ɸ��Ƿ� �����佺�׳׽��� ü�� ���� �����
// ����Ͽ� �ڵ��� �ϴ� ���� �ð��� ���̰� ȿ�����̴�.