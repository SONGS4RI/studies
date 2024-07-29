package main

import (
	"fmt"
	"os"
)

func Read(fileName string) {
	data, err := os.ReadFile(fileName)

	if err != nil {
		panic(err)
	}
	fmt.Println(string(data))
}

func Write(fileName string, message string) {
	bytes := []byte(message)

	err := os.WriteFile(fileName, bytes, 644)

	if err != nil {
		panic(err)
	}
}

func main() {
	// 파일 생성
	fileName := "test.txt"
	fileInfo, _ := os.Stat(fileName)

	// 파일 정보 확인
	if fileInfo != nil {
		fmt.Printf("%s deleted\n", fileName)
		os.Remove(fileName)
	}

	// 생성
	file, err := os.Create(fileName)
	if err != nil {
		panic(err)
	}

	defer file.Close()
	fmt.Printf("%+v\n", fileInfo)
	Write(fileName, "hi my name is")
	Read(fileName)
}
