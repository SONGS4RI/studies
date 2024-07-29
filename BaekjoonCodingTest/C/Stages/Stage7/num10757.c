#include<stdio.h>
#include<stdlib.h>

void reverse(char arr[]) {
	int len = strlen(arr); //�迭�� ���� ����
	char temp;
	for (int i = 0; i < len / 2; i++) { //len/2������ �ٲ�ġ���ϸ� �ڿ��� �ٲ�������
		temp = arr[i];
		arr[i] = arr[len - i - 1];
		arr[len - i - 1] = temp;   //��ȯ�ؼ� �Ųٷ� �ٲ�
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
	//�迭�� ũŰ�� �� ū ���� max�� strlen���� ��������
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
		n3[i] = sum % 10 + '0';  //10���� �������� ������ ������ ������ ���ٸ� �ݿø��� 1�̵ǰ� 1���ڸ� ���ڳ���
	}
	if (halfup == 1)
		n3[max] = '1';
	reverse(n3);
	printf("%s", n3);
}