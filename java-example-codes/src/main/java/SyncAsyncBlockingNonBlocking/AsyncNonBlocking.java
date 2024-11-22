package SyncAsyncBlockingNonBlocking;

import java.util.concurrent.CompletableFuture;

public class AsyncNonBlocking {
    public static void main(String[] args) {
        System.out.println("작업 시작");

        CompletableFuture<String> future = CompletableFuture.supplyAsync(() -> {
            try {
                Thread.sleep(2000); // 비동기 작업 시뮬레이션
                return "비동기 작업 완료";
            } catch (InterruptedException e) {
                return "작업 실패";
            }
        });

        future.thenAccept(System.out::println);// 비동기 작업이 종료되면 실행 되는 콜백

        System.out.println("메인 스레드 계속 실행");

        // 비동기 작업이 완료될 때까지 프로그램 종료 방지
        try {
            Thread.sleep(3000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
