package algorithm;

import java.util.Arrays;

public class SelectionSort {
	public static void main(String[] args) {
		int[] arr = {6, 2, 1, 4, 5, 3};
		for (int idx = 0; idx < arr.length - 1; idx++) {
			int target = idx;
			for (int i = idx + 1; i < arr.length; i++) {
				if (arr[i] < arr[target]) {
					target = i;
				}
			}
			int tmp = arr[idx];
			arr[idx] = arr[target];
			arr[target] = tmp;
			System.out.println(idx + 1 + "회전: " + Arrays.toString(arr));
		}
	}
}
