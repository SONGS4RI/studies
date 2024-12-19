package com.kafka.impl.example;

import org.apache.kafka.clients.producer.KafkaProducer;
import org.apache.kafka.clients.producer.Producer;
import org.apache.kafka.clients.producer.ProducerConfig;
import org.apache.kafka.clients.producer.ProducerRecord;

import java.util.Properties;

public class ExactlyOnceProducer {
    public static void main(String[] args) {
        Properties props = new Properties();
        props.put("bootstrap.servers", "localhost:29092,localhost:39092,localhost:49092");
        props.put("key.serializer", "org.apache.kafka.common.serialization.StringSerializer");
        props.put("value.serializer", "org.apache.kafka.common.serialization.StringSerializer");
        props.setProperty(ProducerConfig.ENABLE_IDEMPOTENCE_CONFIG, "true"); //이전에 전송한 메시지가 중복되지 않도록 보장합니다.
        props.setProperty(ProducerConfig.ACKS_CONFIG, "all"); //모든 ISR이 메시지를 수신할 때까지 기다립니다.
        props.setProperty(ProducerConfig.MAX_IN_FLIGHT_REQUESTS_PER_CONNECTION, "5"); //각 연결당 5개의 요청만 보내도록 합니다.
        props.setProperty(ProducerConfig.RETRIES_CONFIG, "5"); //메시지 전송이 실패하면 무한히 재시도합니다.
        props.setProperty(ProducerConfig.TRANSACTIONAL_ID_CONFIG, "test-topic-transaction-01"); //트랜잭션을 위한 고유한 ID를 설정합니다.

        Producer<String, String> producer = new KafkaProducer<>(props);

        producer.initTransactions(); //트랜잭션을 초기화합니다.
        producer.beginTransaction(); //트랜잭션을 시작합니다.

        try {
            for (int i = 0; i < 1; i++) {
                ProducerRecord<String, String> record = new ProducerRecord<>("test-topic", "test message" + i);
                producer.send(record);
                producer.flush();
                System.out.println("Message sent successfully");
            }
        } catch (Exception e) {
            producer.abortTransaction(); //트랜잭션을 취소합니다.
            e.printStackTrace();
        } finally {
            producer.commitTransaction();
            producer.close(); //프로듀서를 닫습니다.
        }

    }
}
