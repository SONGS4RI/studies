// main_test.go
package main

import "testing"

// TestAdd는 Add 함수의 동작을 테스트합니다.
func TestAdd(t *testing.T) {
	result := Add(3, 5)
	expected := 8

	if result != expected {
		t.Errorf("Add(3, 5) = %d; want %d", result, expected)
	}
}
