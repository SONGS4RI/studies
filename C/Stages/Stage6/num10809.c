#include<stdio.h>

int main() {
    char s1[100] = { 0, };
    int cnt = 0,res[26] = {0,};
    scanf("%s", &s1);

    for (int i = 0; i < 100; i++)
    {
        if (s1[i] != 0) cnt++;
        for (int j = i + 1; j < 100; j++)
        {
            if (s1[i] == s1[j]) s1[j] = ' ';
        }
    }
    for (int i = 0; i < 26; i++) res[i] = -1;
    for (int i = 0; i < cnt; i++)
    {
        int k = (int)s1[i];
        for (int j = 97; j < 123; j++)
        {
            if ( k == j) res[j - 97] = i;
        }
    }
    for (int i = 0; i < 26;i++) printf("%d ", res[i]);
    return 0;
}

// better code!

// #include <stdio.h>
// int main(void)
// {
// char word[100] = { 0 };
// scanf("%s", word);
// for (int i = 97; i <= 122; i++) {
// int j = 0;
// while (word[j] != 0) {
// if (word[j] == (char)i) break;
// j++;
// }
// if (word[j] == (char)i) printf("%d ", j);
// else printf("-1 ");
// }
// }
