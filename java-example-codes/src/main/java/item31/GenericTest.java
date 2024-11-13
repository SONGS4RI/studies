package item31;

public class GenericTest<E> {
    public void test(E e) {
        System.out.println(e);
    }

    public static void main(String[] args) {
        GenericTest<String> t = new GenericTest<>();
//        t.test(new Integer(1));
        t.test("123");
    }
}
