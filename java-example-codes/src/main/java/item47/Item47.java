package item47;

import java.util.*;
import java.util.stream.IntStream;
import java.util.stream.Stream;
import java.util.stream.StreamSupport;

public class Item47 {
    public static void main(String[] args) {
        // 자바 타입 추론의 한계로 컴파일되지 않는다.
//        for (ProcessHandle ph : ProcessHandle.allProcesses()::iterator) {}
        // 스트림을 반복하기 위한 끔직한 방법
        for (ProcessHandle ph : (Iterable<ProcessHandle>) ProcessHandle.allProcesses()::iterator) {
            System.out.println(ph.info());
        }

        for (ProcessHandle ph : Adapters.iterableOf(ProcessHandle.allProcesses())) {
            System.out.println(ph.info());
        }
    }

    // 스트림 <-> 반복자 어댑터 (285-286쪽)
    public static class Adapters {
        // 코드 47-3 Stream<E>를 Iterable<E>로 중개해주는 어댑터 (285쪽)
        public static <E> Iterable<E> iterableOf(Stream<E> stream) {
            return stream::iterator;
        }

        // 코드 47-4 Iterable<E>를 Stream<E>로 중개해주는 어댑터 (286쪽)
        public static <E> Stream<E> streamOf(Iterable<E> iterable) {
            return StreamSupport.stream(iterable.spliterator(), false);
        }
    }

    public static class PowerSet {
        // 코드 47-5 입력 집합의 멱집합을 전용 컬렉션에 담아 반환한다. (287쪽)
        public static final <E> Collection<Set<E>> of(Set<E> s) {
            List<E> src = new ArrayList<>(s);
            if (src.size() > 30)
                throw new IllegalArgumentException(
                        "집합에 원소가 너무 많습니다(최대 30개).: " + s);
            return new AbstractList<Set<E>>() {
                @Override public int size() {
                    // 멱집합의 크기는 2를 원래 집합의 원소 수만큼 거듭제곱 것과 같다.
                    return 1 << src.size();
                }

                @Override public boolean contains(Object o) {
                    return o instanceof Set && src.containsAll((Set)o);
                }

                @Override public Set<E> get(int index) {
                    Set<E> result = new HashSet<>();
                    for (int i = 0; index != 0; i++, index >>= 1)
                        if ((index & 1) == 1)
                            result.add(src.get(i));
                    return result;
                }
            };
        }

        public static void main(String[] args) {
            Set s = new HashSet(Arrays.asList(args));
            System.out.println(PowerSet.of(s));
        }
    }

    // 리스트의 모든 부분리스트를 원소를 갖는 스트림을 생성하는 두 가지 방법 (288-289쪽)
    public class SubLists {
        // 코드 47-6 입력 리스트의 모든 부분리스트를 스트림으로 반환한다. (288-289쪽)
        public static <E> Stream<List<E>> of(List<E> list) {
            return Stream.concat(Stream.of(Collections.emptyList()),
                    prefixes(list).flatMap(SubLists::suffixes));
        }

        private static <E> Stream<List<E>> prefixes(List<E> list) {
            return IntStream.rangeClosed(1, list.size())
                    .mapToObj(end -> list.subList(0, end));
        }

        private static <E> Stream<List<E>> suffixes(List<E> list) {
            return IntStream.range(0, list.size())
                    .mapToObj(start -> list.subList(start, list.size()));
        }

//    // 코드 47-7 입력 리스트의 모든 부분리스트를 스트림으로 반환한다(빈 리스트는 제외). (289쪽)
//    // 289쪽의 명확한 반복 코드의 변형이다.
//    public static <E> Stream<List<E>> of(List<E> list) {
//        return IntStream.range(0, list.size())
//                .mapToObj(start ->
//                        IntStream.rangeClosed(start + 1, list.size())
//                                .mapToObj(end -> list.subList(start, end)))
//                .flatMap(x -> x);
//    }

        public static void main(String[] args) {
            List<String> list = Arrays.asList(args);
            SubLists.of(list).forEach(System.out::println);
        }
    }
}
