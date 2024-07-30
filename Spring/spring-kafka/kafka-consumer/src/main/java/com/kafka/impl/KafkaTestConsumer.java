package com.kafka.impl;

import org.springframework.kafka.annotation.KafkaListener;
import org.springframework.stereotype.Component;

@Component
public class KafkaTestConsumer {
    @KafkaListener(topics = "topic", groupId = "group_1")
    public void listen(Object data) {
        System.out.println(data);
    }
}
