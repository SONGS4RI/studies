# Getting Started

- 카프카 클러스터 구성을 위한 docker-compose 파일을 제공합니다. 
- spring-cloud-stream 을 통해 카프카 메시지를 송수신하는 예제를 제공합니다. 
- 메시지 처리 오류 발생시 DLQ로 메시지를 전달하는 예제를 제공합니다.

1. 카프카 실행. 토픽은 /script/init-topics.sh 로 자동 생성
   test-topic, test-topic-dlq
    ```bash
        docker-compose up -d
    ```
2. api
   1. 메시지 송신
   ```json
    POST http://localhost:8080/message/send
    {
      "productName": "사탕",
      "productCode": 1
    }
   ``` 
   2. 메시지 수신
   ```json
   GET http://localhost:8080/message/consume
   ```
   3. DLQ 메시지 수신
   ```json
   GET http://localhost:8080/message/consume/dlq
   ```