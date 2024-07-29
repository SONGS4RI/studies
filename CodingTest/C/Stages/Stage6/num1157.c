#include <stdio.h>

int main()
{
	char arr[1000000] = { 0, };
	int cnt[26] = { 0, };
	scanf("%s", &arr);
	int i=0,err=0,max=0,index= 0;
	while (arr[i] != 0)                // 대소문자 상관없이 cnt[26]에 갯수 저장
	{
		for (int j = 65; j < 91; j++)
		{
			if (arr[i] == (char)j) cnt[j - 65]++;
		}
		for (int j = 97; j < 123; j++)
		{
			if (arr[i] == (char)j) cnt[j - 97]++;
		}
		i++;
	}
	for (int i = 0; i < 26; i++)
	{
		
		if (cnt[i] > max && cnt[i]!=0)           // 최댓값 갱신 및 index 값 지정
		{
			max = cnt[i];
			index = i;
			err = 0;
		}
		else if (cnt[i] == max && cnt[i] != 0) err++; // 최댓값과 동일할시 err값 변경
	}
	if (err == 0)
	{
		printf("%c", index + 'A');
	}
	else
	{
		printf("?");
	}
	return 0;
}