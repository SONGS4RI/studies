package main

import (
	"fmt"
	"myproject/something"
	"strings"
)

func multiply(a, b int) int {
	return a * b
}

func lenAndUpper(name string) (int, string) {
	return len(name), strings.ToUpper(name)
}

func lenAndLower(name string) (lenght int, lower string) {
	lenght = len(name)
	lower = strings.ToLower(name)
	return
}

func superAdd(numbers ...int) int {
	var total int = 0
	for _, num := range numbers {
		total += num
	}
	return total
}

func repeatMe(words ...string) {
	defer fmt.Println("I'm done")
	fmt.Println(words)
}

func canIDrink(age int) bool {
	// if korAge := age + 1; korAge < 18 {
	// 	return false
	// }
	// return true
	switch koreanAge := age + 2; koreanAge {
	case 10:
		return false
	case 18:
		return true
	}
	return false
}


type person struct {
	name string
	age int
	favFood []string	
}
func main() {
	something.SayHello()
	// something.sayBye()//

	fmt.Println(multiply(10, 5))

	totalLen, changedName := lenAndUpper("bob")
	fmt.Printf("len: %d, Upper: %s\n", totalLen, changedName)

	totalLen, changedName = lenAndLower("BOB")
	fmt.Printf("len: %d, Lower: %s\n", totalLen, changedName)

	repeatMe("nico", "lynn", "dal", "marl", "flyn")

	total := superAdd(-1, -2, -3, -4, -5, -6)
	println(total)

	println(canIDrink(17))
	// pointer
	a := 2
	b := &a
	a = 10
	fmt.Println(a, *b)
	// slice array
	names := []string{"nico", "lynn", "dal"}
	names = append(names, "alala")

	fmt.Println(names)
	// map
	nico := map[string]string{"name": "nico", "age":  "12"}
	for key, value := range nico {
		fmt.Println(key, value)
	}
	//struct
	foods := []string{"kimchi", "noodle"}
	bob := person{name: "bob", age: 18, favFood: foods}
	fmt.Println(bob.name)
}
