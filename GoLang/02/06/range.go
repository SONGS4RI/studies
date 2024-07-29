package main

import (
	"fmt"
)

type Obj struct {
    Name string
    Age  int
}

func PrintObject(list []Obj) {
    for index, object := range list {
        fmt.Printf("index: %d, object: %+v\n", index, object)
    }
}

func main() {
	// for 문은 기본 형식과 while 문 형식으로 사용 가능하다.
	for index := 1; index <= 10; index++ {
		fmt.Printf("index: %d\n", index)
	}

	index := 1
	for true {
		fmt.Printf("index: %d\n", index)
		if index >= 10 {
			break
		}
		index++
	}

	// for, range 문(foreach 형식)
	arr := []string{"A", "B", "C"}
	for i, str := range arr {
		fmt.Printf("i: %d, str: %s\n", i, str)
	}

	dictionary := map[string]string{  
		"key_A": "value_A",  
		"key_B": "value_B",  
	}

	for key, value := range dictionary {  
		fmt.Printf("key: %s, value: %s\n", key, value)  
	}

	// range loop 객체
	list := []Obj{
        {"Beckham", 11},
        {"Zidane", 7},
        {"Ronaldo", 9},
    }

    for _, object := range list {
        object.Age = object.Age * 2
    }

    // 출력, 11, 7, 9
    PrintObject(list)

    for index := range list {
        object := &list[index]
        object.Age = object.Age * 2
    }

  // 출력, 22, 14, 18
    PrintObject(list)
}