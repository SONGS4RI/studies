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
	totalPages := getPages()
	for i := 1; i <= totalPages; i++ {
		getPageDatas(i)
	}
	for i, e := range extracts {
		fmt.Printf("%d: %s %s %s\n", i, e.title, e.location, e.corp)
	}
}

func getPageDatas(pageNum int) {
	pageURL := baseURL + "&recruitPage=" + strconv.Itoa(pageNum)
	res, err := http.Get(pageURL)
	checkErr(err)
	checkCode(res)

	defer res.Body.Close()

	doc, err := goquery.NewDocumentFromReader(res.Body)
	checkErr(err)

	doc.Find(".item_recruit").Each(func(i int, s *goquery.Selection) {
		// title
		title, _ := s.Find(".job_tit a").Attr("title")
		// href
		href, _ := s.Find(".job_tit a").Attr("href")
		href = "https://www.saramin.co.kr" + href
		// corp
		corp := strings.TrimSpace(s.Find(".corp_name a").Text())

		extracts = append(extracts, extractedJob{title: title, location: href, corp: corp})
	})
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

//div class="area_job"
//<a target="_blank" title="파이썬 개발자" onclick="try{s_trackApply(this, &#39;search&#39;, &#39;generic&#39;)}catch(e){};" rel="" class="data_layer" data-data_layer="keyword_free|paid_n" href="/zf_user/jobs/relay/view?view_type=search&amp;rec_idx=48123519&amp;location=ts&amp;searchword=python&amp;searchType=search&amp;paid_fl=n&amp;search_uuid=f84cc277-6350-4bfe-b3ab-17743d5ddc83">

/*
<div class="pagination">
<a href="#recruit_info" page="2" class=" page page_move track_event" data-track_event="total_search|search_recruit|pagination|2">


*/
