package main

func main() {
	// 정수형 채널을 생성한다
	ch1 := make(chan int)

	go func() {
		ch1 <- 123 //채널에 123을 보낸다
	}()

	var i int
	i = <-ch1 // 채널로부터 123을 받는다
	println(i)

	// ch <- 1// 수신 루틴이 없어 데드락 발생
	// println(<- ch)// 코멘트만 해도 데드락

	ch2 := make(chan int, 1)// 버퍼 설정
	ch2 <- 101
	println(<- ch2)
}
