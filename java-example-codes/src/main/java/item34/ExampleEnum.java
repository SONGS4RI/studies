package item34;

public enum ExampleEnum {
    CONSTANT_A, CONSTANT_B;

    private static final int STATIC_VALUE = initializeStaticValue(); // 정적 필드

    // 생성자
    ExampleEnum() {
        System.out.println("Constructor called for: " + this);
    }

    // 정적 필드 초기화 메서드
    private static int initializeStaticValue() {
        System.out.println("Initializing STATIC_VALUE...");
        return 100;
    }
}

