package com.example.springcloudstreamkafka.message.service;

import com.example.springcloudstreamkafka.share.infra.eventbus.ProductMessageQueue;
import com.example.springcloudstreamkafka.share.domain.Product;
import org.springframework.cloud.stream.function.StreamBridge;
import org.springframework.stereotype.Service;

@Service
public class MessageService {
    private final StreamBridge streamBridge;
    private final ProductMessageQueue productMessageQueue;

    public MessageService(StreamBridge streamBridge, ProductMessageQueue productMessageQueue) {
        this.streamBridge = streamBridge;
        this.productMessageQueue = productMessageQueue;
    }

    public void sendMessage(Product product) {
        boolean sent = streamBridge.send("test-topic", product);
        if (sent) {
            System.out.println("Message sent successfully to test-topic" + " : " + product);
        } else {
            System.out.println("Message sending failed to test-topic" + " : " + product);
        }
    }

    public void consumeMessage() {
        System.out.println("Consuming message: " + productMessageQueue.buffer.poll());
    }

    public void consumeDqlMessage() {
        System.out.println("Consuming DQL message: " + productMessageQueue.dlq.poll());
    }
}
