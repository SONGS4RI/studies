package algorithm;

import java.util.Arrays;

public class BubbleSort {
	public static void main(String[] args) {
		Integer[] list = {2, 6, 1, 5, 4, 3};
		for (int i = 0; i < list.length - 1; i++) {
			for (int j = 1; j < list.length - i; j++) {
				if (list[j - 1] > list[j]) {
					int tmp = list[j - 1];
					list[j - 1] = list[j];
					list[j] = tmp;
				}
			}
			System.out.println(Arrays.toString(list));
		}
	}
}
