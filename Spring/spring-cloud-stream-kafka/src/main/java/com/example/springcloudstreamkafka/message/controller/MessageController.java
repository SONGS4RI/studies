package com.example.springcloudstreamkafka.message.controller;

import com.example.springcloudstreamkafka.message.service.MessageService;
import com.example.springcloudstreamkafka.share.domain.Product;
import org.springframework.web.bind.annotation.*;

@RestController
@RequestMapping("/message")
public class MessageController {
    private final MessageService messageService;

    public MessageController(MessageService messageService) {
        this.messageService = messageService;
    }

    @PostMapping("/send")
    public void sendMessage(@RequestBody Product product) {
        messageService.sendMessage(product);
    }

    @GetMapping("/consume")
    public void consumeMessage() {
        messageService.consumeMessage();
    }

    @GetMapping("/consume/dlq")
    public void consumeDqlMessage() {
        messageService.consumeDqlMessage();
    }
}
