package com.kafka.impl;

import org.springframework.kafka.annotation.KafkaListener;
import org.springframework.stereotype.Component;

@Component
public class KafkaConsumer {
    @KafkaListener(topics = "test-topic", groupId = "test-group")
    public void listen(Object data) {
        System.out.println(data);
    }
}
