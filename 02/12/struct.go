package main

import "fmt"

// struct 정의
type person struct {
    name string
    age  int
}

type dict struct {  
    data map[int]string  
 }  
 
 //생성자 함수 정의  
 func newDict() *dict {  
    d := dict{}  
    d.data = map[int]string{}  
    return &d //포인터 전달  
 }  

func main() {
    // person 객체 생성
    p := person{}

    // 필드값 설정
    p.name = "Lee"
    p.age = 10

    fmt.Println(p)

    // 초기화
    var p1 person 
    p1 = person{"Bob", 20}
    p1.name = "Bab"
    p2 := person{name: "Sean", age: 50}
    p2.age = 10


    // new 를 이용한 초기화 
    pnew := new(person)
    pnew.name = "Lee"  // p가 포인터라도 . 을 사용한다

    // 생성자 함수 
    dic := newDict()
    dic.data[1] = "A"
}
