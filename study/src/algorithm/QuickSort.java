package algorithm;

import java.util.*;

public class QuickSort {
	private static void swap(int[] arr, int i, int j) {
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}

	private static int partition(int[] arr, int low, int high) {
		int pivot = arr[low];
		int i = low;
		int j = high;

		while (i < j) {
			while (i <= high && arr[i] <= pivot) {
				i++;
			}
			while (j >= low && arr[j] > pivot) {
				j--;
			}
			if (i < j) swap(arr, i, j);
		}
		swap(arr, low, j);
		System.out.println(Arrays.toString(arr));
		System.out.println(low + " ~ " + high + ", i: " + i + ", j: " + j);
		return j;
	}

	public static void quickSort(int[] arr, int low, int high) {
		if (low < high) {
			int pivotIndex = partition(arr, low, high);
			quickSort(arr, low, pivotIndex - 1);
			quickSort(arr, pivotIndex + 1, high);
		}
	}

	public static void main(String[] args) {
		int[] arr = {6, 1, 4, 5, 3, 2};
		quickSort(arr, 0, arr.length - 1);
	}
}
