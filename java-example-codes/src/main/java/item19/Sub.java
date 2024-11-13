package item19;

import java.time.Instant;

public final class Sub extends Super {
    private final Instant instant;

    Sub() {
        instant = Instant.now();
    }

    // ������ ���� �޼���. ���� Ŭ������ �����ڰ� ȣ���Ѵ�.
    @Override public void overrideMe() {
        System.out.println(instant);
    }

    public static void main(String[] args) {
        Sub sub = new Sub();
        sub.overrideMe();
    }
}
