package main

import (
	"log"
	"os"
)

type error interface {
	Error() string
}

type MyError struct {
	Message string
}

func (e *MyError) Error() string {
	return e.Message
}

func doSomething() error {
	return &MyError{Message: "my error occured"}
}

func main() {
	// 사용자 정의 에러를 잡을 때
	myError := doSomething()
	if myError != nil {
		println(myError.Error())
	}

	f, err := os.Open("C:\\temp\\1.txt")
	if err != nil {
		log.Fatal(err.Error())
	}
	println(f.Name())
}
