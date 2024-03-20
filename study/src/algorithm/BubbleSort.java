package algorithm;

import java.util.Arrays;

public class BubbleSort {
	public static void main(String[] args) {
		Integer[] list = {2, 6, 1, 5, 4, 3};
		boolean sorted = false;
		for (int i = 0; i < list.length - 1 && !sorted; i++) {
			sorted = true;
			for (int j = 1; j < list.length - i; j++) {
				if (list[j - 1] > list[j]) {
					sorted = false;
					int tmp = list[j - 1];
					list[j - 1] = list[j];
					list[j] = tmp;
				}
			}
			System.out.println(i+1 + "회전: " + Arrays.toString(list));
		}
	}
}
