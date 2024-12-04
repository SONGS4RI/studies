package com.kafka.impl;

import lombok.RequiredArgsConstructor;
import org.springframework.http.ResponseEntity;
import org.springframework.kafka.core.KafkaTemplate;
import org.springframework.web.bind.annotation.*;

import java.util.HashMap;
import java.util.Map;

@RestController
@RequestMapping("/message")
@RequiredArgsConstructor
public class MessageController {
    private final KafkaTemplate<String, Object> kafkaTemplate;

    @PostMapping("/send")
    public ResponseEntity<?> msg(@RequestBody Product product) {
        kafkaTemplate.send("test-topic", product);

        Map<String, String> response = new HashMap<>();
        response.put("message", "[" + product + "] sent to topic");

        return ResponseEntity.ok(response);
    }
}
