#include <stdio.h>
int main()
{
	int t,r;
	char s[20];
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		int j= 0;
		scanf("%d %s", &r, &s);

		while (s[j] != 0)
		{
			for (int k = 0; k < r; k++)
			{
				printf("%c", s[j]);
			}
			j++;
		}

		printf("\n");
	}

	return 0;
}
