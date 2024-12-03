package com.example.springcloudstreamkafka.share.infra.eventbus;

import com.example.springcloudstreamkafka.share.domain.Product;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.integration.support.MessageBuilder;
import org.springframework.messaging.Message;

import java.util.function.Supplier;

@Configuration
public class MessageProducer {
    @Bean
    public Supplier<Message<Product>> output() {
        return () -> {
            System.out.println("Sending message to queue");
            Product product = new Product("Supplier Product", 0, false);

            return MessageBuilder
                    .withPayload(product)
                    .build();
        };
    }
}
