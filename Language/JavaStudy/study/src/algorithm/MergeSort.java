package algorithm;

import java.util.Arrays;

public class MergeSort {
	public static void merge(int[] arr, int left, int right) {
		int mid = (left + right) / 2;
		int[] L = Arrays.copyOfRange(arr, left, mid + 1);
		int[] R = Arrays.copyOfRange(arr, mid + 1, right + 1);

		int i = 0, j = 0;

		while (i < L.length && j < R.length) {
			arr[left] = L[i] <= R[j] ? L[i++] : R[j++];
			left++;
		}

		// remain
		while (i < L.length) {
			arr[left++] = L[i++];
		}
		while (j < R.length) {
			arr[left++] = R[j++];
		}
	}
	public static void mergeSort(int[] arr, int left, int right) {
		if (left < right) {
			int mid = (left + right) / 2;
			mergeSort(arr, left, mid);
			mergeSort(arr, mid + 1, right);
			merge(arr, left, right);
			System.out.println(Arrays.toString(arr));
		}
	}

	public static void main(String[] args) {
		int[] arr = {6, 1, 3, 5, 2, 4};
		mergeSort(arr, 0, arr.length - 1);
	}
}
