package item31;

import java.util.ArrayList;
import java.util.Collection;
import java.util.List;
import java.util.concurrent.ScheduledFuture;

public class Stack<E> {
//    public Stack();
//    public void push(E e);
//    public E pop();
//    public boolean isEmpty();
//    public void pushAll() {
//        for (E e : src) {
//            push(e);
//        }
//    }
//
//    public void popALl(Collection<E> dst) {
//        while (!isEmpty()) {
//            dst.add(pop());
//        }
//    }

    public static <E extends Comparable<E>> E max(List<E> list) {
        if (list.isEmpty()) {
            return null;
        }
        E max = list.get(0);
        for (int i = 1; i < list.size(); i++) {
            if (max.compareTo(list.get(i)) > 0) {
                max = list.get(i);
            }
        }
        return max;
    }

    public static <E extends Comparable<? super E>> E maxWildcard(List<? extends E> list) {
        if (list.isEmpty()) {
            return null;
        }
        E max = list.get(0);
        for (int i = 1; i < list.size(); i++) {
            if (max.compareTo(list.get(i)) > 0) {
                max = list.get(i);
            }
        }
        return max;
    }


    public static void main(String[] args) {
        List<ScheduledFuture<?>> futures = new ArrayList<>();
//        max(futures);
        maxWildcard(futures);
    }
}
