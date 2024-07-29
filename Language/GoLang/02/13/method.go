package main

//Rect - struct 정의
type Rect struct {
    width, height int
}

//Rect의 area() 메소드
func (r Rect) area() int {
	r.width++// 실제 값이 변경되지 않는다. 항상 포인터로 받았을 때만 변경된다.
    return r.width * r.height   
}

// 포인터 Receiver
func (r *Rect) area2() int {
    r.width++
    return r.width * r.height
}

func main() {
    rect := Rect{10, 20}
    area1 := rect.area() //메서드 호출
    println(rect.width, area1)

	area2 := rect.area2() //메서드 호출
    println(rect.width, area2) // 11 220 출력
}
