package algorithm;

import java.util.*;

public class InsertionSort {
	public static void main(String[] args) {
		int[] arr = {2, 1, 6, 5, 4, 3};

		for (int idx = 1; idx < arr.length; idx++) {
			int tmp = arr[idx];
			int prev = idx - 1;
			while (prev >= 0 && arr[prev] > tmp) {
				arr[prev + 1] = arr[prev];
				prev--;
			}
			arr[prev + 1] = tmp;
			System.out.println(idx + "회전: " + Arrays.toString(arr));
		}
	}
}
