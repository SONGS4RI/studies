package testlib

import "fmt"

var pop map[string]string

func init() { // 패키지 로드시 map 초기화
	pop = make(map[string]string)
	fmt.Println("init!")
}

func Hi() {
    fmt.Println("hi")
    fmt.Printf("%+v", pop)
}