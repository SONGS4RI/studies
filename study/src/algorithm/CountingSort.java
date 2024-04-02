package algorithm;

import java.util.Arrays;

public class CountingSort {
	void sort(int[] arr) {
		int n = arr.length;
		// 배열에서 최대값과 최소값 찾기
		int max = arr[0];
		int min = arr[0];
		for (int i = 1; i < n; i++) {
			if (arr[i] > max) {
				max = arr[i];
			}
			if (arr[i] < min) {
				min = arr[i];
			}
		}
		// 카운트 배열 초기화
		int range = max - min + 1;
		int[] count = new int[range];
		// 입력 배열의 각 요소 카운팅
		for (int i = 0; i < n; i++) {
			count[arr[i] - min]++;
		}
		System.out.println("count 배열:" + Arrays.toString(count));
		// 카운트 배열 변경: 각 값이 최종적으로 위치할 시작 인덱스를 반영
		for (int i = 1; i < range; i++) {
			count[i] += count[i - 1];
		}
		System.out.println("count 배열:" + Arrays.toString(count));
		// 결과 배열 생성 및 입력 배열의 요소 배치
		int[] output = new int[n];
		for (int i = n - 1; i >= 0; i--) {
			output[--count[arr[i] - min]] = arr[i];
		}
		// 원래 배열에 정렬된 요소 복사
		System.arraycopy(output, 0, arr, 0, n);
	}

	public static void main(String[] args) {
		CountingSort cs = new CountingSort();
		int[] arr = {4, 2, 2, 8, 3, 3, 1};
		System.out.println("정렬 전 배열:" + Arrays.toString(arr));
		cs.sort(arr);
		System.out.println("정렬 후 배열:" + Arrays.toString(arr));
	}
}
