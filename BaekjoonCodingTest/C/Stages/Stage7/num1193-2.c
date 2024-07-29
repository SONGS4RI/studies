#include<stdio.h>

int main() {
	int a;
	int ans;
	int l = 1;
	int b = 1;
	int i, j;
	
	scanf("%d", &a);
	
	if(a == 1) {
		i = 1;
		j = 1;
	} else {
		while(a > b) {
			b += ++l;
		}
		if(l % 2 != 0) {
			i = b - a + 1;
			j = a - (b - l);
		} else {
			i = a - (b - l);
			j = b - a + 1;
		}
	}

	printf("%d/%d", i, j);
	return 0;
}