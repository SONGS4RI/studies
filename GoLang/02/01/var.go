package main
import "fmt"

const i = 1;
const s string = "string";

// iota는 각 상수에 자동으로 값을 할당하며, 기본적으로 0부터 시작해서 선언할 때 마다 1 씩 증가합니다.
const (
	A = iota;
	B;
	C;
	D;
);

func main() {
	// var 선언
	var i1 int = 10;
	var s1 string = "string";
	fmt.Println(i1);
	fmt.Println(s1);

	// 타입 생략 가능
	var i2 = 10
	var s2 = "string";
	fmt.Println(i2);
	fmt.Println(s2);

	// := 를 이용한 변수 선언
	i3 := 10
	s3 := "string"
	fmt.Println(i3)
	fmt.Println(s3)

	// 다수의 변수를 동시에 선언
	var i4, j4, k4 int = 10, 11, 12;
	s4, t4, u4 := "string1", "string2", "string3";
	fmt.Println(i4, j4, k4);
	fmt.Println(s4, t4, u4);

	// var()를 이용한 변수 선언
	var (
		i7 = 1;
		j8 = 2;
		k9 = 3;
		s10, s11, s12 = "string1", "string2", "string3";
	);
	fmt.Println(i7, j8, k9);
	fmt.Println(s10, s11, s12);

	// 상수
	fmt.Println(i);
	fmt.Println(s);
	fmt.Println(A, B, C, D);
}