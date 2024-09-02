package item30;

import java.util.HashSet;
import java.util.Set;
import java.util.function.UnaryOperator;

public class Main {
    private static UnaryOperator<Object> IDENTITY_FN = (t) -> t;

    @SuppressWarnings("unchecked")
    public static <T> UnaryOperator<T> identityFunction() {
        return t -> t;
    }

    public static <E> Set<E> union(Set<E> set1, Set<E> set2) {
        Set<E> result = new HashSet<E>();

        result.addAll(set1);
        result.addAll(set2);

        return result;
    }

    public static void main(String[] args) {
        String[] strings = {"a", "b", "c", "d", "e", "f", "g", "h"};
        UnaryOperator<String> sameString = identityFunction();
        for (String s : strings) {
            System.out.println(sameString.apply(s));
        }
    }
}
