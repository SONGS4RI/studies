package item39;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

public class RunTests {
    public static void main(String[] args) throws Exception {
        int tests = 0;
        int passed = 0;
        String[] classes = {"item39.Sample1", "item39.Sample2", "item39.Sample3"};
        for (String className : classes) {
            Class<?> testClass = Class.forName(className);
            for (Method m : testClass.getDeclaredMethods()) {
                if (m.isAnnotationPresent(Test.class)) {
                    tests++;
                    try {
                        m.invoke(null);
                        passed++;
                    } catch (InvocationTargetException wrappedExc) {
                        Throwable exc = wrappedExc.getCause();
                        System.out.println(m + " 실패: " + exc);
                    } catch (Exception exc) {
                        System.out.println("잘못 사용한 @Test: " + m);
                    }
                }

                if (m.isAnnotationPresent(ExceptionTest.class)) {
                    tests++;
                    try {
                        m.invoke(null);
                        System.out.printf("테스트 %s 실패: 예외를 던지지 않음%n", m);
                    } catch (InvocationTargetException wrappedEx) {
                        Throwable exc = wrappedEx.getCause();
                        Class<? extends Throwable> excType =
                                m.getAnnotation(ExceptionTest.class).value();
                        if (excType.isInstance(exc)) {
                            passed++;
                        } else {
                            System.out.printf(
                                    "테스트 %s 실패: 기대한 예외 %s, 발생한 예외 %s%n",
                                    m, excType.getName(), exc);
                        }
                    } catch (Exception exc) {
                        System.out.println("잘못 사용한 @ExceptionTest: " + m);
                    }
                }
            }

            System.out.printf("성공: %d, 실패: %d%n", passed, tests - passed);
        }
    }
}
