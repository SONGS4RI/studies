package item26;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class Raw {
    public static void main(String[] args) {
        List<String> strings = new ArrayList<>();
//        unsafeAdd(strings, Integer.valueOf(42));
//        String s = strings.get(0); // 컴파일러가 자동으로 형변환 코드를 넣어준다.

        System.out.println("==========================");
        Set<String> s1 = Set.of("1", "2", "3");
        Set<String> s2 = Set.of("4", "5", "6");
        Set<Integer> s3 = Set.of(1, 2, 3);
        System.out.println(D(s1, s2));
        System.out.println(D(s1, s3));
    }

    /**
     * 런타임 단에서 에러 발생
     * @param list
     * @param o
     */
    private static void unsafeRawAdd(List list, Object o) {
        list.add(o);
    }

    /**
     * 컴파일러단에서 에러 발생
     * @param list
     * @param o
     */
    private static void unsafeAdd(List<Object> list, Object o) {
        list.add(o);
    }

    static int D(Set<?> s1, Set<?> s2) {
        int result = 0;
        for (Object o : s1) {
            if (s2.contains(o)) {
                result++;
            }
        }
        return result;
    }
}
