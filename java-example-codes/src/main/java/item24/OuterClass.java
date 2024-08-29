package item24;

import java.util.HashMap;
import java.util.Map;

public class OuterClass {

    // 바깥 클래스의 private 필드
    private static String staticOuterField = "Outer class static private field";
    private String instanceOuterField = "Outer class instance private field";

    // 정적 멤버 클래스
    public static class StaticInnerClass {
        public void accessOuterStaticField() {
            // 바깥 클래스의 정적 private 필드에 접근 가능
            System.out.println("Accessing: " + staticOuterField);
        }

        public void accessOuterInstanceField(OuterClass outer) {
            // 바깥 클래스의 인스턴스 필드에 접근하려면 인스턴스를 통해 접근
            System.out.println("Accessing: " + outer.instanceOuterField);
        }
    }

    public static void main(String[] args) {
        // 바깥 클래스의 인스턴스 생성
        OuterClass outer = new OuterClass();
        // 정적 멤버 클래스의 인스턴스 생성
        StaticInnerClass staticInner = new StaticInnerClass();
        // 정적 필드에 접근
        staticInner.accessOuterStaticField();  // 출력: Accessing: Outer class static private field
        // 인스턴스 필드에 접근
        staticInner.accessOuterInstanceField(outer);  // 출력: Accessing: Outer class instance private field
        Map map = new HashMap();


    }
}

