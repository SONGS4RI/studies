package SyncAsyncBlockingNonBlocking;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class SyncBlocking {
    public static void main(String[] args) {
        // 파일 읽기동안 블록킹 되어지고 동기화 되어진다.
        try (BufferedReader br = new BufferedReader(new FileReader("file.txt"))) {
            System.out.println("파일 읽기 시작");

            String line;
            while ((line = br.readLine()) != null) {
                System.out.println(line);
            }

            System.out.println("파일 읽기 완료");
        } catch (IOException e) {
            System.out.println(e.getMessage());

        }
    }
}
