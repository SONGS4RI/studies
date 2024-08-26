package item20;

public interface TestInterface {
    /**
     * public static final이 필드값의 기본이어서 생략 가능
     */
    public static final  int one = 1;
    int two = 2;

    default void defaultFunction() {
        System.out.println("default function");
    }

    /**
     * static void publicStaticFunction()와 동일
     */
    public static void publicStaticFunction() {
        System.out.println("publicStaticFunction");
    }

    private static void privateStaticFunction() {
        System.out.println("privateStaticFunction");
    }
}
