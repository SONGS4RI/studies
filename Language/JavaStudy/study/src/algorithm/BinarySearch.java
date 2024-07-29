package algorithm;

import java.util.Arrays;
import java.util.NoSuchElementException;

public class BinarySearch {
	public static int binarySearch(int[] arr, int target) {
		Arrays.sort(arr);
		int s = 0;
		int e = arr.length - 1;
		int mid;

		while (s <= e) {
			mid = (s + e) / 2;
			if (arr[mid] == target) {
				return mid;
			}
			if (arr[mid] < target) {
				s = mid + 1;
			} else {
				e = mid - 1;
			}
		}
		throw new NoSuchElementException("타겟 존재하지 않음");
	}

	public static void main(String[] args) {
		int[] arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		int target = 6;
		System.out.println(target + "의 인덱스: " + binarySearch(arr, target));
		try {
			target = 11;
			System.out.println(target + "의 인덱스: " + binarySearch(arr, target));
		} catch (Exception e) {
			System.out.println(e);
		}
	}
}
