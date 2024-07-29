package main

import (
	"fmt"
	"myproject/banking"
	"myproject/dict"
)

func main() {
	account := banking.NewAccount("jahoon")
	fmt.Println(account.GetOwner(), account.GetBalance())
	account.Deposit(10000)
	fmt.Println(account.GetOwner(), account.GetBalance())
	err := account.Withdraw(50000)
	if err != nil {
		fmt.Println(err)
	}
	fmt.Println(account.GetOwner(), account.GetBalance())
	fmt.Println(account)

	dictionary := dict.Dictionary{}
	dictionary["hello"] = "hellooooo"
	fmt.Println(dictionary)
	if res, err := dictionary.Search("hello"); err != nil {
		fmt.Println(err)
	} else {
		fmt.Println(res)
	}
	err = dictionary.Add("hello", "Greeting")
	if err != nil {
		fmt.Println(err)
	}
	definition, err := dictionary.Search("hello")
	if err != nil {
		fmt.Println(err)
	} else {
		fmt.Println(definition)
	}
}
