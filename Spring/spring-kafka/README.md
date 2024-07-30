# 스프링 부트 + kafka 예제 입니다.

1. `docker-compose up -d` 실행하여 카프카 + 주키퍼 컨테이너 등록
2. kafka-consumer, kafka-producer 모듈 실행
3. `http://localhost:8081/send?msg=테스트 메시지 1` 과 같이 메시지 전송
4. kafka-consumer 에서 로그 확인
