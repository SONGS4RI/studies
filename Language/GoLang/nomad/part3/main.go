package main

import (
	"errors"
	"fmt"
	"net/http"
	"sync"
	"time"
)

var errRequestFailed = errors.New("request failed")

func main() {
	var results = make(map[string]string)

	urls := []string{
		"https://www.airbnb.com/",
		"https://www.google.com/",
		"https://www.amazon.com/",
		"https://www.reddit.com/",
		"https://www.google.com/",
		"https://soundcloud.com/",
		"https://www.facebook.com/",
		"https://www.instagram.com/",
		"https://academy.nomadcoders.co/",
	}
	ch := make(chan error, 1)
	for _, url := range urls {
		go hitURL(url, ch)		
	}
	for _, url := range urls {
		result := "OK"
		if <- ch != nil {
			result = "FAILED"
		}
		results[url] = result
	}

	for url, result := range results {
		fmt.Println(url, result)
	}
}

func hitURL(url string, ch chan <- error) {
	fmt.Println("Checking:", url)
	resp, err := http.Get(url)
	if err != nil || resp.StatusCode >= 400 {
		fmt.Println(err)
		ch <- err
		return
	}
	ch <-nil
}

func sexyCount(person string, wg *sync.WaitGroup) {
	defer wg.Done()
	for i:=0; i<5; i++ {
		fmt.Println(person, "is sexy", i)
		time.Sleep(time.Second)
	}
}