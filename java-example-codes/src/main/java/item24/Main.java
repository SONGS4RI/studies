package item24;

public class Main {
    public static void main(String[] args) {
        OuterClass outerClass = new OuterClass();

        OuterClass.StaticInnerClass staticInnerClass = new OuterClass.StaticInnerClass();
        staticInnerClass.accessOuterStaticField();

        staticInnerClass.accessOuterInstanceField(outerClass);
    }
}
