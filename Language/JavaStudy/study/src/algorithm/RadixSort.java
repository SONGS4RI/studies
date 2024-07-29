package algorithm;

import java.util.*;

public class RadixSort {
	// 기수 정렬 함수
	public static void radixSort(int[] arr) {
		// 배열 중 최대값 찾기
		int max = Arrays.stream(arr).max().getAsInt();
		// 최대 자릿수만큼 반복
		for (int exp = 1; max / exp > 0; exp *= 10) {
			countSort(arr, exp);
		}
	}

	// exp는 현재 정렬할 자릿수를 의미 (1 -> 10 -> 100 -> ...)
	private static void countSort(int[] arr, int exp) {
		int n = arr.length;
		int[] output = new int[n]; // 정렬된 배열을 담을 공간
		int[] count = new int[10]; // 숫자의 빈도수를 저장할 배열 (0-9)
		// 현재 자릿수(exp)에 따른 빈도수 계산
		for (int i = 0; i < n; i++) {// 0:2, 2:2, 4:1, 5:2, 6:1
			count[(arr[i] / exp) % 10]++;
		}
		// 누적 합계 계산
		for (int i = 1; i < 10; i++) {
			count[i] += count[i - 1];
		}
		// 누적 합계를 이용하여 출력 배열을 생성
		for (int i = n - 1; i >= 0; i--) {
			output[count[(arr[i] / exp) % 10] - 1] = arr[i];
			count[(arr[i] / exp) % 10]--;
		}

		// 정렬된 배열을 원래 배열에 복사
		for (int i = 0; i < n; i++) {
			arr[i] = output[i];
		}
		System.out.println(exp + "자리수: " + Arrays.toString(arr));
	}

	public static void main(String[] args) {
		int[] arr = {170, 45, 75, 90, 802, 24, 2, 66};
		radixSort(arr);
		System.out.println("정렬된 배열: " + Arrays.toString(arr));
	}
}
