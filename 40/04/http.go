package main

import (
	"io"
	"net/http"
	"os"
	"time"

	log "github.com/sirupsen/logrus"
)

func main() {
	var request *http.Request
	var responseBody []byte
	var err error
	// 로그 파일 열기
	logfileName := "logfile.log"

	logfile, err := os.OpenFile(logfileName, os.O_CREATE|os.O_WRONLY|os.O_TRUNC, 0666)
	if err != nil {
		log.Fatalf("Failed to open log file: %s", err)
	}
	defer logfile.Close()
	log.SetOutput(logfile) // 로그 파일로 지정

	log.SetLevel(log.DebugLevel) // 디버그레벨로 기록 설정

	requestUrl := "http://www.naver.com"

	if request, err = http.NewRequest(http.MethodGet, requestUrl, nil); err != nil {
		log.Errorf("error: %s", err)
		panic(err)
	}

	request.Header.Add("accept", "application/json")

	query := request.URL.Query()
	// query.Add("query-key", "query-value")
	request.URL.RawQuery = query.Encode()

	client := &http.Client{
		Timeout: 30 * time.Second,
	}
	// 리퀘스트 요청
	response, err := client.Do(request)

	if err != nil {
		log.Errorf("error: %s", err)
		panic(err)
	}

	// 함수가 종료 될 때 응답 본문 닫기
	defer func(Body io.ReadCloser) {
		err := Body.Close()
		if err != nil {
			panic(err)
		}
	}(response.Body)

	// 응답 본문 읽기
	responseBody, err = io.ReadAll(response.Body)

	if err != nil {
		log.Errorf("error: %s", err)
	}

	log.Debugf("RequestURI: %s", request.URL.String())
	log.Debugf("Method: %s", request.Method)
	log.Debugf("ResponseBody: %s", responseBody)
}
