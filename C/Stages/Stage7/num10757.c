#include<stdio.h>
#include<stdlib.h>

void reverse(char arr[]) {
	int len = strlen(arr); //배열의 개수 리턴
	char temp;
	for (int i = 0; i < len / 2; i++) { //len/2까지만 바꿔치기하면 뒤에도 바껴져있음
		temp = arr[i];
		arr[i] = arr[len - i - 1];
		arr[len - i - 1] = temp;   //교환해서 거꾸로 바꿈
	}
}



int main() {
	char n1[10002];
	char n2[10002];
	char n3[10002] = { 0 };
	scanf("%s %s", &n1, &n2);
	reverse(n1);
	reverse(n2);
	int sum = 0;
	int halfup=0;

	int len1 = strlen(n1);
	int len2 = strlen(n2);
	int max = 0;
	//배열의 크키가 더 큰 것을 max에 strlen으로 저장해줌
	if (len1 > len2)
		max = len1;
	else
		max = len2;
	for (int i = 0; i < max; i++) {
		sum = n1[i] - '0' + n2[i] - '0'+halfup;
		if (sum < 0) {
			sum += '0';
		}
		if (sum >= 10) {
			halfup = 1;
		}
		else {
			halfup = 0;
		}
		n3[i] = sum % 10 + '0';  //10보다 작은수를 나누면 본인이 나오고 높다면 반올림이 1이되고 1의자리 숫자나옴
	}
	if (halfup == 1)
		n3[max] = '1';
	reverse(n3);
	printf("%s", n3);
}