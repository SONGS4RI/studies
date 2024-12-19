package com.kafka.impl.example;

import org.apache.kafka.clients.producer.KafkaProducer;
import org.apache.kafka.clients.producer.Producer;
import org.apache.kafka.clients.producer.ProducerRecord;

import java.util.Properties;

import static java.lang.Thread.sleep;

public class ProducerAsync {
    public static void main(String[] args) throws InterruptedException {
        Properties props = new Properties();
        props.put("bootstrap.servers", "localhost:29092,localhost:39092,localhost:49092");
        props.put("key.serializer", "org.apache.kafka.common.serialization.StringSerializer");
        props.put("value.serializer", "org.apache.kafka.common.serialization.StringSerializer");

        Producer<String, String> producer = new KafkaProducer<>(props);

        try {
            for (int i = 0; i < 3; i++) {
                ProducerRecord<String, String> record = new ProducerRecord<>("test-topic", "Apache Kafka is a distributed streaming platform - " + i); //ProducerRecord 오브젝트를 생성합니다.
                producer.send(record, new PeterProducerCallback(record)); //프로듀서에서 레코드를 보낼 때 콜백 오브젝트를 같이 보냅니다.
                System.out.println("sleep start");
                sleep(5000);
                System.out.println("sleep end");
            }
        } catch (Exception e){
            e.printStackTrace();
        } finally {
            producer.close(); // 프로듀서 종료
        }


    }
}
