package SyncAsyncBlockingNonBlocking;

import java.util.concurrent.atomic.AtomicBoolean;

public class SyncNonBlocking {
    public static void main(String[] args) throws InterruptedException {
        AtomicBoolean isReady = new AtomicBoolean(false);
        System.out.println("Job A 시작");
        // 비동기 작업을 시뮬레이션하는 스레드
        new Thread(() -> {
            try {
                System.out.println("Job B 시작");
                Thread.sleep(3000); // 3초 대기
                System.out.println("Job B 완료");
                isReady.set(true);
            } catch (InterruptedException e) {
                System.out.println(e.getMessage());
            }
        }).start();

        System.out.println("Job A 완료");

        // 동기적으로 작업 완료를 확인하지만, 블로킹하지 않음
        while (!isReady.get()) {
            System.out.println("Job B 아직 완료 전, Job A 다른 작업 수행");
            Thread.sleep(500); // 0.5초마다 확인
        }

        System.out.println("작업이 완료되었습니다.");
    }
}
