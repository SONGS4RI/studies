package algorithm;

import java.util.*;

public class HeapSort {
	public static void main(String[] args) {
		int[] arr = { 230, 10, 60, 550, 40, 220, 20 };

		heapSort(arr);
		System.out.println(Arrays.toString(arr));
	}

	public static void heapify(int arr[], int n, int i) {
		int p = i;
		int l = i * 2 + 1;
		int r = i * 2 + 2;

		if (l < n && arr[p] < arr[l]) {
			p = l;
		}

		if (r < n && arr[p] < arr[r]) {
			p = r;
		}

		if (i != p) {
			swap(arr, p, i);
			heapify(arr, n, p);
		}
	}

	public static void heapSort(int[] arr) {
		int n = arr.length;

		for (int i = n / 2 - 1; i >= 0; i--) {// 부모 노드들에 대해서
			heapify(arr, n, i);
		}
		// 현재 루트 노드가 가장 큰 수
		for (int i = n - 1; i > 0; i--) {
			swap(arr, 0, i);
			heapify(arr, i, 0);
		}
	}

	public static void swap(int[] arr, int a, int b) {
		int tmp = arr[a];
		arr[a] = arr[b];
		arr[b] = tmp;
	}
}
