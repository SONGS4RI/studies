package main

import (
	"fmt"
	"math/rand"
	"os"
	"time"
)

func main() {
	// if 사용
	seed := time.Now().UnixNano();
    randSource := rand.NewSource(seed);
    random := rand.New(randSource);
    i := random.Intn(15);

    fmt.Println(i);

    if i < 10 {
        fmt.Println("A");
    } else if i == 10 {
        fmt.Println("B");
    } else {
        fmt.Println("C");
    }

    // -------- if condition -----------
    str := "Hello World!";
	filePath := "hello.txt";
	if _, err := os.Stat(filePath); err == nil {
        // 파일이 존재하면 삭제
        err := os.Remove(filePath);
        if err != nil {
            fmt.Println("파일 삭제 중 오류 발생:", err);
        } else {
            fmt.Println("파일이 성공적으로 삭제되었습니다.");
        }
    } else if os.IsNotExist(err) {
        // 파일이 존재하지 않음
        fmt.Println("파일이 존재하지 않습니다.");
    } else {
        // 다른 오류 발생
        fmt.Println("파일 상태 확인 중 오류 발생:", err);
    }

    if err := os.WriteFile("hello.txt", []byte(str), 0644); err != nil {
        fmt.Println(err);
    }

	fmt.Println("=======================================================");

	random = rand.New(randSource);
    i = random.Intn(15);
	fmt.Println(i)
	switch i {
		case 0, 1:
			fmt.Println("A")
		case 2, 3, 4:
			fmt.Println("B")
		case 5:
			fmt.Println("C")
		default:
			fmt.Println("D")
    }
}
