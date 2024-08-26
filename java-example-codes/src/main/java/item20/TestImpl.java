package item20;


public class TestImpl implements TestInterface {
    public static void main(String[] args) {
        TestInterface t = new TestImpl();
        t.defaultFunction();

        TestInterface.publicStaticFunction();
//        private access
//        TestInterface.privateStaticFunction();
    }
}
