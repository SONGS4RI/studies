package com.example.springcloudstreamkafka.share.infra.eventbus;

import com.example.springcloudstreamkafka.share.domain.Product;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.integration.support.MessageBuilder;
import org.springframework.messaging.Message;

import java.util.function.Consumer;

@Configuration
public class MessageConsumer {
    private final ProductMessageQueue productMessageQueue;

    public MessageConsumer(ProductMessageQueue productMessageQueue) {
        this.productMessageQueue = productMessageQueue;
    }

    @Bean
    public Consumer<Message<Product>> input() throws RuntimeException {
        return message -> {
            boolean added = productMessageQueue.buffer.offer(message);
            if (!added) {
                // dlq 설정을 해두었다면 자동으로 설정되어진 토픽으로 메시지 전송
                throw new RuntimeException("Queue is full, message discarded: " + message);
            }
            System.out.println("Message added to queue: " + message.getPayload() + ", headers: " + message.getHeaders());
        };
    }

    @Bean
    public Consumer<Message<Product>> dlq() {
        return message -> {
            Product product = message.getPayload();
            Product dqlProduct = new Product(
                    product.productName(),
                    product.productCode(),
                    true
            );
            Message<Product> modifiedMessage = MessageBuilder
                    .withPayload(dqlProduct)
                    .copyHeaders(message.getHeaders())
                    .build();

            boolean added = productMessageQueue.dlq.offer(modifiedMessage);
            if (!added) {
                throw new RuntimeException("DLQ is full, message discarded: " + modifiedMessage.getPayload());
            }

            System.out.println("Message added to DLQ: " + modifiedMessage.getPayload());
        };
    }
}
