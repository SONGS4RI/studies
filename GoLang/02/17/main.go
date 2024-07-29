// main.go
package main

import "fmt"

// Add 함수는 두 정수를 더하여 반환합니다.
func Add(a, b int) int {
	return a + b
}

func main() {
	fmt.Println("3 + 5 =", Add(3, 5))
}
