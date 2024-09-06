package item32;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.ThreadLocalRandom;

public class Main {

	static <T> T[] toArray(T... args) {
		return args;
	}

	static <T> T[] pickTwo(T a, T b, T c) {
		switch (ThreadLocalRandom.current().nextInt(3)) {
			case 0: return toArray(a, b);
			case 1: return toArray(a, c);
			case 2: return toArray(b, c);
		}
		throw new AssertionError();
	}

	static void dangerous(List<String>... stringLists) {
		List<Integer> intList = List.of(42);
		Object[] objects = stringLists;
		objects[0] = intList;
		String s = stringLists[0].get(0);
	}

	@SafeVarargs
	static <T> List<T> flatten(List<? extends T>... lists) {
		List<T> result = new ArrayList<>();
		for (List<? extends T> list : lists) {
			result.addAll(list);
		}
		// List.of();
		return result;
	}


	public static void main(String[] args) {
		String[] attributes = pickTwo("좋은", "빠른", "저렴한");
	}
}
