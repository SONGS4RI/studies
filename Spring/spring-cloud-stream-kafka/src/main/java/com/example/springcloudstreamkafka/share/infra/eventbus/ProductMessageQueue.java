package com.example.springcloudstreamkafka.share.infra.eventbus;

import com.example.springcloudstreamkafka.share.domain.Product;
import org.springframework.messaging.Message;
import org.springframework.stereotype.Component;

import java.util.concurrent.BlockingQueue;
import java.util.concurrent.LinkedBlockingQueue;

@Component
public class ProductMessageQueue {
    public final BlockingQueue<Message<Product>> buffer = new LinkedBlockingQueue<>(1000);
    public final BlockingQueue<Message<Product>> dlq = new LinkedBlockingQueue<>(1000);
}
