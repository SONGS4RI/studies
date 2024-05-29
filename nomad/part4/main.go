package main

import (
	"fmt"
	"log"
	"net/http"
	"strconv"
	"strings"

	"github.com/PuerkitoBio/goquery"
)

type extractedJob struct {
	title    string
	location string
	corp     string
}

var baseURL string = "https://www.saramin.co.kr/zf_user/search/recruit?&searchword=python&recruitPageCount=40"
var extracts = []extractedJob{}

func main() {
	ch := make(chan []extractedJob, 1)
	totalPages := getPages()
	for i := 1; i <= totalPages; i++ {
		go getPageDatas(i, ch)
	}
	for i := 1; i <= totalPages; i++ {
			extracts = append(extracts, <- ch...)
	}
	for i, e := range extracts {
		fmt.Printf("%d: %s [%s] URL: %s\n", i, e.title, e.corp, e.location)
	}
}

func getPageDatas(pageNum int, ch chan<- []extractedJob) {
	pageURL := baseURL + "&recruitPage=" + strconv.Itoa(pageNum)
	res, err := http.Get(pageURL)
	checkErr(err)
	checkCode(res)

	defer res.Body.Close()

	doc, err := goquery.NewDocumentFromReader(res.Body)
	checkErr(err)
	result := []extractedJob{}
	doc.Find(".item_recruit").Each(func(i int, s *goquery.Selection) {
		// title
		title, _ := s.Find(".job_tit a").Attr("title")
		// href
		href, _ := s.Find(".job_tit a").Attr("href")
		href = "https://www.saramin.co.kr" + href
		// corp
		corp := strings.TrimSpace(s.Find(".corp_name a").Text())
		result = append(result, extractedJob{title: title, location: href, corp: corp})
	})
	ch <- result
}

func getPages() int {
	pages := 0
	res, err := http.Get(baseURL)
	checkErr(err)
	checkCode(res)

	defer res.Body.Close()

	doc, err := goquery.NewDocumentFromReader(res.Body)
	checkErr(err)

	doc.Find(".pagination").Each(func(i int, s *goquery.Selection) {
		pages = s.Find("a").Length()
	})
	return pages
}

func checkErr(err error) {
	if err != nil {
		log.Fatalln(err)
	}
}

func checkCode(res *http.Response) {
	if res.StatusCode != 200 {
		log.Fatalln("Request failed with status:", res.StatusCode)
	}
}
