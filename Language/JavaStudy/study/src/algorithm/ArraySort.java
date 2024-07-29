package algorithm;

import java.util.*;

public class ArraySort {
	public static void main(String[] args) {
		int[][] arr = new int[5][2];
		for (int i = 0; i < arr.length; i++) {
			arr[i][0] = i;
			arr[i][1] = (int)(Math.random() * 100);
			System.out.println(Arrays.toString(arr[i]));
		}
		System.out.println("=======================");
		Arrays.sort(arr, (a, b) -> {
			if (a[1] == b[1]) {
				return a[0] - b[0];
			}
			return b[1] - a[1];
		});
		for (int[] a : arr) {
			System.out.println(Arrays.toString(a));
		}
	}
}
