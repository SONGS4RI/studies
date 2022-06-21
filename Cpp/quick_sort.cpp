#include<iostream>
using namespace std;

int Partiton(int arr[], int left, int right); // 퀵 정렬 메소드 (나누기)
void QuickSort(int arr[], int left, int right); // 퀵 정렬 메소드 (재귀)
void Swap(int *A, int *B); // 값 교환 메소드
void ShowArr(int arr[], int length); // 배열 출력 메소드

void ShowArr(int arr[], int length) // 배열 출력 메소드
{
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void Swap(int *A, int *B) // 값 교환 메소드 (call by address)
{
	int Temp = *A;
	*A = *B;
	*B = Temp;
}

int Partiton(int arr[], int left, int right) // 퀵정렬 나누기 메소드
{
	int first = left;
	int pivot = arr[first]; // 기준 배열

	while (left<=right)
	{
		while (arr[left] <= pivot && left < right)
			++left;
		while (arr[right] >= pivot && left <= right)
			--right;
		if (left < right)
			Swap(&arr[left], &arr[right]);
		else
			break;
		
	}
	Swap(&arr[first], &arr[right]);

	return right;
}
void QuickSort(int arr[], int left, int right) // 퀵정렬 메소드
{
	if (left < right)
	{
		int index = Partiton(arr, left, right);// 파티션 메소드 실행 (리턴값 right)

		QuickSort(arr, left, index - 1); // 재귀함수 기준 왼쪽으로 메소드 실행
		QuickSort(arr, index + 1, right); // 재귀함수 기준 오른쪽으로  메소드 실행
	}
}

int main()
{
	int Arr[] = { 4,12,2,7,1,3,9 }; // 정렬에 사용될 배열
	int length = sizeof Arr / sizeof Arr[0]; // 배열의 길이
	
	cout << "배열크기 : " << length << endl;// 배열 크기(lengh) 출력
	ShowArr(Arr, length); // 배열 출력 메소드 실행
	QuickSort(Arr, 0, length-1); // 퀵 정렬 메소드 실행
	ShowArr(Arr, length); // 정렬이 완료된 배열 출력 메소드 실행
	
	return 0;
}